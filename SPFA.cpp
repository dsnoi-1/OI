#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,s;

struct edge{
	int to;
	long long w;
	edge(int a,long long b){
		to=a,w=b;
	}
};
vector<edge> g[maxn];

long long dis[maxn],cnt[maxn];
bitset<maxn> vis;
queue<int> q;

bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	int now;
	while(!q.empty()){
		now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=0;i<g[now].size();++i){
			edge gi=g[now][i];
			if(dis[now]+gi.w<dis[gi.to]){
				dis[gi.to]=dis[now]+gi.w;
				cnt[gi.to]=cnt[now]+1;
				if(cnt[gi.to]>=n){
					return true;//ÓÐ¸º»· 
				}
				if(!vis[gi.to]){
					q.push(gi.to);
					vis[gi.to]=1;
				}
			}
		}
	}
	return false;
}
int main(){
	cin>>n>>m>>s;
	int u,v;
	long long w;
	for(int i=0;i<m;++i){
		cin>>u>>v>>w;
		g[u].push_back(edge(v,w));
	}
	spfa();
	for(int i=1;i<=n;++i){
		if(dis[i]<4557430888798830399ll){
			cout<<dis[i]<<' ';
		} 
		else{
			cout<<INT_MAX<<' ';
		}
	}
	return 0;
}
