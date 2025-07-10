#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
struct edge{
    int to,w;
};
int n,m;
int dis[maxn],cnt[maxn];
bool inq[maxn];
vector<edge> g[maxn];
bool spfa(int s){
    queue<int> q;
    q.push(s);
    inq[s]=1;
    cnt[s]=1;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        inq[node]=0;
        for(edge y:g[node]){
            if(dis[node]+y.w<dis[y.to]){
                dis[y.to]=dis[node]+y.w;
                if(!inq[y.to]){
                    inq[y.to]=1;
                    ++cnt[y.to];
                    q.push(y.to);
                    if(cnt[y.to]>n){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;++i){
        g[0].push_back({i,0});
    }
    if(spfa(0)){
        cout<<"NO";
    }
    else{
        for(int i=1;i<=n;++i){
            cout<<dis[i]<<' ';
        }
    }
    return 0;
}