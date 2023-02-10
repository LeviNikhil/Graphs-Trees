#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


vector<pair<ll,ll>> v; //For storing the coordinates of lakes which we have to remove

ll dfs2(ll i,ll j,ll n,ll m,vector<vector<char>>&grid)
{
     if(i==n || j==m || i<0 || j<0 || grid[i][j]=='*') return 0;

     grid[i][j]='*';
     v.push_back({i,j});

     ll sz=1+dfs2(i+1,j,n,m,grid) + dfs2(i-1,j,n,m,grid) + 
            dfs2(i,j+1,n,m,grid) + dfs2(i,j-1,n,m,grid);

      return sz;
}


void dfs(ll i,ll j,ll n,ll m,vector<vector<char>>&grid)
{
     if(i==n || j==m || i<0 || j<0 || grid[i][j]=='*') return;

     grid[i][j]='*';

     dfs(i+1,j,n,m,grid);
     dfs(i-1,j,n,m,grid);
     dfs(i,j+1,n,m,grid);
     dfs(i,j-1,n,m,grid);
}

void solve(){
     ll n,m,k;
     cin>>n>>m>>k;

     vector<vector<char>> grid(n,vector<char>(m,'.'));

     for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
     }

     auto Finalgrid=grid;

     //Lets resolve borders

     for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<m;j++)
        {
            if((i==0 || j==0 || i==n-1 || j==m-1) && (grid[i][j]=='.'))
            {
                dfs(i,j,n,m,grid);
            }
        }
     }

     vector<pair<ll,vector<pair<ll,ll>>>> data; //stores size of lake and coordinates

     for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            {
                v.clear();
                ll sz=dfs2(i,j,n,m,grid);
                data.push_back({sz,v});
            }
        }
     }

     sort(data.begin(),data.end());

     ll currlakes=data.size();
     ll cnt=currlakes;
     ll changes=0;

     for(auto el:data)
     {
        if(cnt==k) break;

        changes+=el.second.size();

        for(auto cord:el.second)
        {
            Finalgrid[cord.first][cord.second]='*';
        } 
        cnt--;      
     }
     cout<<changes<<endl;

     for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<m;j++)
        {
            cout<<Finalgrid[i][j];
        }
        cout<<endl;
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
