#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct edge{
	int to;
	edge(int a){
		to=a;
	}
};
vector<edge> g[maxn];
int n,p;
int r[maxn];
bitset<maxn> vis;

void toposort(){
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!r[i]){
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty()){
		int node=q.front();
		cout<<node<<' ';
		q.pop();
		for(int i=0;i<g[node].size();++i){
			int next=g[node][i].to;
			--r[next];
			if(!r[next] && !vis[next]){
				q.push(next);
				vis[next]=1;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		while(1){
			cin>>p;
			if(p==0){
				break;
			}
			g[i].push_back(edge(p));
			r[p]++;
		}
	}
	toposort();
	return 0;
}
