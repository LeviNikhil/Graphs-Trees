#include<bits/stdc++.h>
using namespace std;

#define ll  long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const ll N=1e5+5;

//number of nodes in a connected component C is x, then except the first node, all other nodes of that 
//component will react doubling the danger every time. So for one connected component the danger will
// be 2^(x-1). Similarly for each connected component the danger will be 2^((# nodes in that component)-1). 
//And the final result will be multiplication of all these results which is 2^(n-v) 
//where v is the number of connected components.

vector<int> ad[100];  //Adjacency list of nodes
int vis[100];   //array for checking if a node is visited or not

void dfs(ll node)
{
    if(vis[node])return;
    vis[node]=1;

    for(ll child : ad[node])     //traversing through nodes to check whether it is visited or not
    {
        if(!vis[child]) dfs(child);
    }
}

void solve(){
   ll n,m,a,b;
   cin>>n>>m;

   for(ll i=1;i<=m;i++)
   {
    cin>>a>>b;          //Creating Adjacency list of nodes for checking which other nodes are connected to given node.
    ad[a].push_back(b);
    ad[b].push_back(a);
   }
   ll cc=0;  //Connected components

   for(ll i=1;i<=n;i++)
   {
    if(!vis[i]) cc++,dfs(i);
   }

    ll ans = pow(2,n)/pow(2,cc);
    cout<<ans;
}

     

   
   
    



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
     // seive();

    IOS;
    ll T;
    T=1;
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
