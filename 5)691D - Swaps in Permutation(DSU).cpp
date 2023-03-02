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

void solve(){
   
    cin>>n>>m;
    for(ll i=1;i<=n;i++) leader[i]=i;
    ll val[n+1];
    for(ll i=1;i<=n;i++) cin>>val[i];
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
    
    vector<ll> values;

    for(ll i=1;i<=n;i++)
    {
        if(find_leader(i)==i)
        {
            //actual leader, hence a new connected component
            // nodes in component = group[i]

            for(auto node:groups[i])
            {
               values.push_back(val[node]);
            }

            sort(values.begin(),values.end(),greater<ll>());

            ll idx=0;

            for(auto node:groups[i])
            {
                val[node]=values[idx];
                idx++;
            }

            values.clear();
        }
    }

    for(ll i=1;i<=n;i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<endl;

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
