#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,cnt;
vector<int> g[maxn];
int del[maxn],out[maxn];
stack<int> ans;
void dfs(int s){
	for(int i=del[s];i<g[s].size();i=del[s]){
		del[s]=i+1;
		dfs(g[s][i]);
	}
	ans.push(s);
}
int main(){
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;++i){
		cin>>u>>v;
		g[u].push_back(v);
		++out[u];
		--out[v];
	}
	for(int i=1;i<=n;++i){
		sort(g[i].begin(),g[i].end());
	}
	int s=1,sum=0;
	for(int i=1;i<=n;++i){
		if(out[i]==1){
			if(!sum){
				s=i;
			}
			++sum;
		}
		if(abs(out[i])>1){
			cout<<"No";
			exit(0);
		}
	}
	if(sum>1){
		cout<<"No";
		exit(0);
	}
	dfs(s);
	while(!ans.empty()){
		cout<<ans.top()<<' ';
		ans.pop();
	}
	return 0;
}
