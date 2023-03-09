#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod=1e9+7;

vector<ll> adj[26];
vector<ll>indegree(26);


void solve(){
     ll n;cin>>n;
     vector<string> vs(n);
     for(ll i=0;i<n;i++) cin>>vs[i];
     for(ll i=0;i+1<n;i++)
     {
        ll id=0;

        while( id< min(vs[i].size(),vs[i+1].size()) and vs[i][id]==vs[i+1][id])
        {
            id++;
        }

        if(id<min(vs[i].size(),vs[i+1].size()))
        {
            adj[vs[i][id]-'a'].push_back(vs[i+1][id]-'a');
            indegree[vs[i+1][id]-'a']++;
        }

        if(id>=vs[i+1].size())
        {
            cout<<"Impossible"<<endl;
            return;
        }
      }
      string ans;
      queue<char> q;
      for(ll i=0;i<26;i++)
      {
         if(indegree[i]==0) q.push(i+'a');
      }

      while(!q.empty())
      {
          ans+=q.front();
          ll i=q.front()-'a';
          q.pop();

          for(auto j : adj[i])
          {
              indegree[j]--;
              if(indegree[j]==0) q.push(j+'a');
          }
      }
      
      if(ans.size()<26)
      {
          cout<<"Impossible"<<endl;
      }
      else 
          cout<<ans<<endl;


     
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
