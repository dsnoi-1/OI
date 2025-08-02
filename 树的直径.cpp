#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,dp[maxn];
vector<int> g[maxn];
void dfs(int u,int fa){
    for(int v:g[u]){
        if(v!=fa){
            dfs(v,u);
            ans=max(ans,dp[v]+dp[u]+1);
            dp[u]=max(dp[u],dp[v]+1);
        }
    }
}
int main(){
    cin>>n;
    int u,v;
    for(int i=1;i<n;++i){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}