#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod=1e9+7;

ll n,m,leader[2000005];
vector<ll> adj[2000005], groups[2000005];

//DSU

ll find_leader(ll x)
{
    if(leader[x]==x) return x;
    else return leader[x] = find_leader(leader[x]);
}

void merge(ll x,ll y)
{
    ll lx=find_leader(x);
    ll ly=find_leader(y);

    if(lx==ly) return;

    leader[ly]=lx;
}

/*
    Graph N nodes M edges , disconnected
    Edges Becoming directed now
    Minimize nodes which doesnt have any incoming edge

    **One connected component
    Strategy:
    1)If cc has a cycle ,assign dirn in clockwise fashion and make one the node
    from this cycle the root, and all edges going downwards.
    else
    2)CC has no cycle it means it is a tree in that case (1) is minm you can get


    Particular CC
    n nodes in component and m edges in the component
    m>=n , it means it has a cycle

    1)Find connected components
    2)Check each component one by one
    3)Check if edges<size of component, if yes ans++;
*/

void solve(){
   
    cin>>n>>m;
    for(ll i=1;i<=n;i++) leader[i]=i;
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        merge(u,v);
    }

    for(ll i=1;i<=n;i++)
    {
        groups[find_leader(i)].push_back(i);
    }
    
    ll ans=0;

    for(ll i=1;i<=n;i++)
    {
        if(find_leader(i)==i)
        {
            //actual leader, hence a new connected component
            // nodes in component = group[i]

            ll edges=0;

            for(auto node:groups[i])
            {
                edges+=(adj[node].size());
            }
            edges/=2;

            if(edges<groups[i].size()) ans++;
        }
    }

    cout<<ans<<endl;

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
