#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m,s,u,v,w;
int minl,k;
int g[maxn][maxn];
long long f[maxn];
bitset<maxn> b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m>>s;
	memset(g,127,sizeof(g));
	for(int i=0;i<m;++i){
		cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
	}
	for(int i=1;i<=n;++i){
		f[i]=g[s][i];
	}
	f[s]=0;
	b[s]=1;
	while(1){
		minl=maxn;
		k=0;
		for(int i=1;i<=n;++i){
			if(!b[i] && f[i]<minl){
				minl=f[i];
				k=i;
			}
		}
		if(k==0){
			break;
		}
		b[k]=1;
		for(int i=1;i<=n;++i){
			f[i]=min(f[i],f[k]+g[k][i]);
		}
	}
	for(int i=1;i<=n;++i){
		cout<<f[i]<<' ';
	}
	return 0;
}
