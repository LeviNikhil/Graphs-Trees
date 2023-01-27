#include<bits/stdc++.h>
using namespace std;

#define ll  long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const ll N=1e5+5;


void solve()
{
        ll n;cin >> n;
        ll a[n];
        map<ll,ll>mp;
        ll maxifreq=0;
        for(ll i=0;i<n;i++){
          cin>>a[i];
          mp[a[i]]++;
        }
        ll ans=0;
        bool val=false;
        ll lastele=0;
        auto it=mp.begin();
             
        while(mp.size()!=0)
        {
             lastele=it->first;
             int change=0;
             if(mp[it->first]&&mp[it->first+1])
             {
                mp[it->first]--;
                if(mp[it->first]==0)
                {
                   change=1;
                   auto ptr=it;
                   ptr++;
                   ll find_ele=ptr->first;
                   ll ele=it->first;
                   mp.erase(ele);
                   it=mp.find(find_ele);
                }
                val=true; 
             }

             if(val==false)
             {
               ans++;
               mp[lastele]--;
               if(mp[lastele]==0){
                  mp.erase(lastele);
               }
               if(mp[lastele+1]==0)
               {
                 mp.erase(lastele+1);
               }
                   
               it=mp.begin();
             }
             else
             {
              if(change==0){
                it++;
              }
              
               val=false;
             }

        }

      cout<<ans<<endl;
 
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
    cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
