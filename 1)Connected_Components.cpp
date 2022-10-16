#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

//Given n,i.e total no of nodes in undirected graph numbered 1 to n & (e)-total no of edges in graph.
//Calculate total no of connected components in graphs.

vector<ll> ad[100001];  //Adjacency list of nodes
ll vis[100001];   //array for checking if a node is visited or not

void dfs(ll node)
{
    vis[node]=1;

    for(ll child : ad[node])     //traversing through nodes to check whether it is visited or not
    {
        if(!vis[child])
            dfs(child);
    }
}

void solve(){
   ll n,m,a,b;
   cin>>n>>m;

   for(ll i=0;i<=m;i++)
   {
    cin>>a>>b;          //Creating Adjacency list of nodes for checking which other nodes are connected to given node.
    ad[a].push_back(b);
    ad[b].push_back(a);
   }
   ll cc=0;  //Connected components

   for(ll i=1;i<=n;i++)
   {
    if(!vis[i]) dfs(i),cc++;
   }

   cout<<cc<<"\n";
}




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    ll T;
    T=1;
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
