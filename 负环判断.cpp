#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
struct edge{
    int to;
    long long w;
    edge(int a,long long b){
        to=a;
        w=b;
    }
};
vector<edge> g[maxn];

int t,n,m;
long long dis[maxn],cnt[maxn];
bitset<maxn> vis;

bool spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=n;++i){
        vis[i]=0;
    }
    queue<int> q;
    dis[1]=0;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0;i<g[u].size();++i){
            int w=g[u][i].w,to=g[u][i].to;
            if(dis[u]+w<dis[to]){
                dis[to]=dis[u]+w;
                cnt[to]=cnt[u]+1;
                if(cnt[to]>=n){
                    return 1;
                }
                if(!vis[to]){
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return 0;
}

int main(){
    int u,v;
    long long w;
    cin>>t;
    for(int i=0;i<t;++i){
        for(int j=0;j<maxn;++j){
            g[j].clear();
        }
        cin>>n>>m;
        for(int j=0;j<m;++j){
            cin>>u>>v>>w;
            if(w>=0){
                g[u].push_back(edge(v,w));
                g[v].push_back(edge(u,w));
            }
            else{
                g[u].push_back(edge(v,w));
            }
        }
        if(spfa()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
