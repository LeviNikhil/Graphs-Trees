#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod=1e9+7;

/*
There are N cities and M bi - directional roads. We need to transport essential items from City 1  to all other cities.
But every road has some positive amount of Toll Charge associated with it say C.
We need to find the minimum amount of charge that it required to deliver essential items for each city.
Fortunately, to our rescue we have K special offers, which means while travelling from City 1 to any 
other city we can select at-most K roads and we will not be charged for using those roads. 
Can you now find the minimum charge that we have to pay to deliver essential items for each city.
*/

/*
   Convert given graph with N nodes to graph with N*(K+1) nodes .Because for every node we have 0 1 2 3 - - -k states
   [i][j]-- Represents that you are at node i in the old graph and you have used j offers till now and
   d[i][j] is the min cost to achieve that.

   Source(1,0)  --- Apply Dijkstra 
   (u,j)--->(v,j)           weight of reqd path=w    For all cycles (u,v) in the original graph.
   (u,j)--->(v,j+1) (j<k)   weight of reqd path=0   (We have used here the discount)
   T.C ---> (N+M)*K*LOG(N*K)
*/

ll n, m, k;
vector<vector<vector<ll>>> adj;

void solve(){

     cin>>n>>m>>k;
     adj.resize(n+1);

     while(m--)
     {
        ll i,j,w;
        cin>>i>>j>>w;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
     }

     vector<vector<ll>> d(n+1,vector<ll>(k+1,INT_MAX));  // i-> 1 to n,  j-> 0 to k

     set<vector<ll>> s;
     s.insert({0,1,0});  // {d,node}
     d[1][0]=0;

     while(!s.empty())
     {
         auto it = s.begin();
         ll i=(*it)[1], j=(*it)[2];

         s.erase(it);

         for(vector<ll> e : adj[i])
         {
            ll nb=e[0], w=e[1];

            if(d[i][j] + w < d[nb][j])            // [u][j] -> [v][j]
            {
                s.erase({d[nb][j],nb,j});
                d[nb][j] = d[i][j] + w;
                s.insert({d[nb][j],nb,j});
            }
            
            if(j<k and d[i][j] + 0 < d[nb][j+1])   // [u][j] -> [v][j+1]
            {
                s.erase({d[nb][j+1] , nb , j + 1 });
                d[nb][j+1] = d[i][j];
                s.insert({d[nb][j+1] , nb , j + 1 });
            }
         }
     }

     for(ll i=1;i<=n;i++)
     {
        cout<<*min_element(d[i].begin(), d[i].end())<<" ";
     }
     cout<<endl;

     
}




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    // pre();
    int T;
    T=1;
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
