#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll mod=1e9+7;
const int maxm=1e5+9;
//Find how many nodes are contributed in diameter

int n;
vector<ll> adj[maxm];
int in[maxm];
int out[maxm];
bool vis[maxm];
int ans[maxm];
int op[maxm];
int freq[maxm];

void dfs(ll u)
{
    vis[u]=true;
    for(ll v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
            in[u]=max(in[u],in[v]+1);
        }
    }
}

void dfs2(ll u)    // Used for calculation of Maxm distances for each node from endpoint of Diameter
{
    vis[u]=true;
    vector<int> val;
    ll sz=0;
    for(ll v: adj[u])
    {
        if(!vis[v])
        {
            val.push_back(in[v]);
            sz++;
            out[v]=out[u]+1;
        }
    }
    int pmax[sz + 1];
    int smax[sz + 1];
    
    pmax[0] = -1;
    smax[sz] = -1;
    for (int i=1; i<=sz; i++){
        pmax[i] = max(pmax[i-1], val[i-1]);
    }
    for (int i=sz-1; i>=0; i--){
        smax[i] = max(smax[i+1], val[i]);
    }
    
    int c = 0;
    for (int v: adj[u]){
        if (!vis[v]){
            out[v] = max(out[v], pmax[c] + 2);
            out[v] = max(out[v], smax[c+1] + 2);
            c++;
        }
    }
    
    for (int v: adj[u]){
        if (!vis[v])
        dfs2(v);
    }


}

void solve(){
    cin>>n;
    ll edges = n-1;
 
    for(ll i=0;i<edges;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   

   // Finding Diametric End points of graph
   dfs(1);
   for(ll i=1;i<=n;i++)
   {
      vis[i]=false;
   }
   dfs2(1);
   int diameter=0;

   for(ll i=1;i<=n;i++)
   {
      ans[i]=max(in[i],out[i]);
      diameter=max(ans[i],diameter);
      freq[ans[i]]++;
   }

   ll total=n;
   for(ll k=n;k>=1;k--)
   {
       total-=freq[k];
       if(k==diameter) total++;
       op[k]=total;
   }

   for(ll i=1;i<=n;i++)
   {
      cout<<op[i]<<" ";
   }
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
