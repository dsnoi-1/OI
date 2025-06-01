#include<bits/stdc++.h>
using namespace std;
const int maxn=(2e5)+10;
int n,m,s,u,v,w;

struct edge{
	int next;
	long long v;
	edge(int a,long long b){
		next=a;
		v=b;
	}
};
vector<edge> g[maxn];

struct node{
	int id;
	long long dis;
	node(int b,long long c){
		id=b;
		dis=c;
	}
	bool operator < (const node &a)const{
		return dis>a.dis;
	}
};

long long d[maxn];
bitset<maxn> done;

int main(){
	cin>>n>>m>>s;
	for(int i=0;i<m;++i){
		cin>>u>>v>>w;
		g[u].push_back(edge(v,w));
	}
	
	memset(d,0x3f,sizeof(d));
	priority_queue<node> q;
	q.push(node(s,0));
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(done[x.id]){
			continue;
		}
		done[x.id]=true;
		d[x.id]=x.dis;
		for(int i=0;i<g[x.id].size();++i){
			edge y=g[x.id][i];
			if(done[y.next]){
				continue;
			}
			if(x.dis+y.v<d[y.next]){
				q.push(node(y.next,x.dis+y.v));
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<d[i]<<' ';
	}
	return 0;
}
