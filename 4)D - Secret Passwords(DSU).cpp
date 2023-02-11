#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

ll find_parent(ll node, vector<ll>&parent)
{
    if(parent[node]==node) return node;
    return parent[node]=find_parent(parent[node],parent);
}

void merge(ll node1, ll node2,vector<ll>&rank, vector<ll>&parent)
{
    ll par1=find_parent(node1,parent);
    ll par2=find_parent(node2,parent);

    if(par1==par2) return;

    if(rank[par1]>rank[par2])
    {
        parent[par2]=par1;
        rank[par1]++;
    }
    else
    {
        parent[par1]=par2;
        rank[par2]++;
    }
}



void solve(){
     
     ll n;cin>>n;
     vector<string>v(n);
     for(ll i=0;i<n;i++) cin>>v[i];
     vector<ll> graph(26,-1);
     vector<ll> parent(n,0);
     for(ll i=0;i<n;i++) parent[i]=i;

     vector<ll> rank(n,0);
     for(ll i=0;i<n;i++)
     {
        string ss =v[i];
        for(ll j=0;j<ss.size();j++)
        {
            ll val=ss[j]-'a';

            if(graph[val]==-1) graph[val]=i;
            else if(graph[val]!=i)
            {
                merge(i,graph[val],rank,parent);
            }
        }
     }

     set<ll>st;
     for(ll i=0;i<n;i++)
     {
        ll par=find_parent(i,parent);
        st.insert(par);
     }
     cout<<st.size()<<endl;
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
