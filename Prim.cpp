#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int ans=0;
struct edge{
	int to,v;
	edge(int a,int b){
		to=a;
		v=b;
	}
};
struct node{
	int id,d;
	node(int a,int b){
		id=a;
		d=b;
	}
	bool operator < (const node &s)const{
		return d>s.d;
	}
};
int n,m;
vector<edge> g[maxn];
bitset<maxn> vis;

void prim(){
	int cnt=0;
	priority_queue<node> q;
	q.push(node(1,0));
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(vis[x.id]){
			continue;
		}
		vis[x.id]=1;
		ans+=x.d;
		++cnt;
		for(int i=0;i<g[x.id].size();++i){
			edge y=g[x.id][i];
			if(vis[y.to]){
				continue;
			}
			q.push(node(y.to,y.v));
		}
	}
	if(cnt==n){
		cout<<ans;
	}
	else{
		cout<<"orz";
	}
}
int main(){
	cin>>n>>m;
	int x,y,z;
	for(int i=0;i<m;++i){
		cin>>x>>y>>z;
		g[x].push_back(edge(y,z));
		g[y].push_back(edge(x,z));
	}
	prim();
	return 0;
}
