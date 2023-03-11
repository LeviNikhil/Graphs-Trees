#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod=1e9+7;
//https://codeforces.com/problemset/problem/1473

/*
   Find the min cost from 1 to any city.Given that while travelling to a particular
   city. you have to subtract exactly 1 edge ka weight from the cost and add exactly 1 edge ka weight
   to the cost
   N*2*2  nodes
   Source  -> [1,0,0]  --->  [i,1,1]
   (u-->v) weight-w
  1) [u,i,j]  _w_->[v,i,j] . . . .   Neither add nor subtract
  2) [u,0,j]  _2*w_->[v,1,j] . . . . Add
  3) [u,i,0]  _0_-> [v,i,1] . . . . . Subtract
  4) [u,0,0]  _w_->[v,1,1] . . . . . . Both add and subtract
*/





void solve(){
     ll n, m;
     cin>>n>>m;
     vector<vector<vector<ll>>> adj(n+1);

     while(m--)
     {
        ll i,j,w;
        cin>>i>>j>>w;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
     }

     vector<vector<vector<ll>>> d(n+1,vector<vector<ll>>(2,vector<ll>(2,INT_MAX)));  // d[n+1][2][2] - {INF}

     set<vector<ll>> s;    // [dist, i, j, k]  node or state -{i,j,k}
     s.insert({0,1,0,0});  // {d,node}
     d[1][0][0]=0;

     //[node][added][subtracted]

     while(!s.empty())
     {
         auto it = s.begin();
         ll i=(*it)[1], j=(*it)[2] , k=(*it)[3];

         s.erase(it);

         for(vector<ll> e : adj[i])        // u -> v  | i -> nb
         {
            ll nb=e[0], w=e[1];

            if(d[i][j][k] + w < d[nb][j][k])            // normal
            {
                s.erase({d[nb][j][k],nb,j,k});
                d[nb][j][k] = d[i][j][k] + w;
                s.insert({d[nb][j][k],nb,j,k});
            }
            
            if(j==0 and d[i][j][k] + 2*w < d[nb][j+1][k])  
            {
                s.erase({d[nb][j+1][k] , nb, j + 1 , k });
                d[nb][j+1][k] = d[i][j][k]+2*w;
                s.insert({d[nb][j+1][k] , nb , j + 1 , k });
            }

            if(k==0 and d[i][j][k] + 0< d[nb][j][k+1])  
            {
                s.erase({d[nb][j][k+1] , nb, j , k + 1 });
                d[nb][j][k+1] = d[i][j][k];
                s.insert({d[nb][j][k+1] , nb , j , k + 1 });
            }

            if(j==0 and k==0 and d[i][j][k] + w < d[nb][j+1][k+1])  
            {
                s.erase({d[nb][j+1][k+1] , nb, j + 1 , k + 1});
                d[nb][j+1][k+1] = d[i][j][k]+w;
                s.insert({d[nb][j+1][k+1] , nb , j + 1 , k + 1 });
            }


         }
     }

     for(ll i=2;i<=n;i++)
     {
        cout<<d[i][1][1]<<" ";
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
