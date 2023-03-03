#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const ll mod=998244353;

vector<vector<ll>> adj;
vector<ll> col;
ll c1, c2;

ll powmod(ll a,ll b,ll p){
     ll r=1; a %= p;
    while(b)
    {
       if(b&1) r = (r*a)%p;
       b>>=1; a = (a*a)%p;
    }
    return r;
}

bool bfs(ll src)
{
    queue<ll>q;
    q.push(src);

    col[src]=1;

    while(!q.empty())
    {
        ll i=q.front();
        q.pop();
         
        if(col[i]==1) c1++;
        else c2++;

        for(ll nb: adj[i])
        {
            if(!col[nb])
            {
                q.push(nb);
                col[nb]=3-col[i];
            }

            else if(col[nb]==col[i]) return 0;
        }


    }

    return 1;
}

void solve(){
   
    ll n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    col.assign(n + 1, 0);

    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll ans=1;

    for(ll i=1;i<=n;i++)
    {
        if(!col[i])
        {
            c1=0, c2=0;
            ans*=bfs(i);
            ans*=(powmod(2,c1,mod)+powmod(2,c2,mod));
            ans%=mod;
        }

        if(!ans)break;

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
    cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
