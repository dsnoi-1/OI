#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
long long ans[maxn][maxn];
long long n,m,u,v,w;
int main(){
	memset(ans,127,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		ans[u][v]=ans[v][u]=min(ans[u][v],w);
	}
	for(int i=1;i<=n;++i){
		ans[i][i]=0;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if((ans[i][k]+ans[k][j]<ans[i][j])
				&&(ans[i][k]<9187201950435737471ll)
				&&(ans[k][j]<9187201950435737471ll)){
					ans[i][j]=ans[i][k]+ans[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
