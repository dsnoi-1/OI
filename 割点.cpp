#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int n,m,dfn,num[maxn],low[maxn];
vector<int> g[maxn];
bool iscut[maxn];
void dfs(int u,int fa){
    num[u]=low[u]=++dfn;
    int child=0;
    for(int i:g[u]){
        if(!num[i]){
            ++child;
            dfs(i,u);
            low[u]=min(low[u],low[i]);
            if(low[i]>=num[u]){
                iscut[u]=1;
            }
        }
        else if(num[i]<num[u] && i!=fa){
            low[u]=min(low[u],num[i]);
        }
    }
    if(fa==0 && child>1){
        iscut[u]=1;
    }
}
int main(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;++i){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        dfs(i,0);
    }
    for(int i=1;i<=n;++i){
        if(iscut[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}