#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


//Problem Based on rerooting technique

/*
    1. Calculate answer for rooted tree--O(T)
    2. Find way to transition in better than O(T)

    A node W contributes size[W] to the answer always.
    Final answer would be (sum of size[W]) for all W
    size[W]--size of subtree of W

    Fix one root at random and Process the size in O(T)
    Now we have to look for good way to transition

    Root
    Child

    copy_root=size[Root]
    copy_child=size[Child]
    size[Root]=size[Root]-size[Child]
    size[Child]=N

    now we have to update child as the new root

    size[Root]=copy_root
    size[Child]=copy_child
*/

ll n,subtree_size[200005],final_ans,sum;
vector<ll> adj[200005];

void dfs(ll node,ll par)
{
    subtree_size[node]=1;
    for(auto child:adj[node])
    {
        if(child==par) continue;

        dfs(child,node);
        subtree_size[node]+=subtree_size[child];
    }
}

void dfs2(ll node,ll par)
{
      //Currently node is root and all values are in accordance with that
      ll ans_when_node_is_root=sum;
      final_ans=max(final_ans,ans_when_node_is_root);
      for(auto child:adj[node])
      {
          if(child==par) continue;
          // Reroot from node to child

          ll copy_root=subtree_size[node];
          ll copy_child=subtree_size[child];
          ll copy_sum=sum;
          subtree_size[node]=subtree_size[node]-subtree_size[child];
          subtree_size[child]=n;
          sum-=(copy_child+copy_root);
          sum+=subtree_size[child]+subtree_size[node];

          //Made child as the root and update the arrays
          dfs2(child,node);

          //Set Root back to node
          subtree_size[node]=copy_root;
          subtree_size[child]=copy_child;
          sum=copy_sum;
      }
}

void solve(){
     
     cin>>n;
     for(ll i=0;i<n-1;i++)
     {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     dfs(1,-1);
     for(ll i=1;i<=n;i++) sum+=subtree_size[i];
     dfs2(1,-1);
     cout<<final_ans<<endl;
     
}




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    int T;
    T=1;
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
