#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,maxm=2e5+5;
struct edge{
	int v,a,b;
}e[maxm];
bool cmp(edge e1,edge e2){
	return e1.v<e2.v;
}
int n,m;
long long ans;
int t[maxn];
int find(int x){
	if(t[x]==x){
		return x;
	}
	return t[x]=find(t[x]);
}
bool add(int x,int y){
	int x1=find(x),y1=find(y);
	if(x1==y1){
		return 1;
	}
	t[x1]=y1;
	return 0;
}
void kruskal(){
	int cnt=1;
	for(int i=0;i<m;++i){
		if(cnt==n){
			break;
		}
		if(add(e[i].a,e[i].b)){
			continue;
		}
		ans+=e[i].v;
		++cnt;
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
	for(int i=1;i<=n;++i){
		t[i]=i;
	}
	for(int i=0;i<m;++i){
		cin>>e[i].a>>e[i].b>>e[i].v;
	}
	sort(e,e+m,cmp);
	kruskal();
	return 0;
}
