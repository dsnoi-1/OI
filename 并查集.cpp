#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int t[maxn];
int n,m;
void init(){
	for(int i=1;i<=n;++i){
		t[i]=i;
	}
}
int find(int x){
	if(x==t[x]){
		return x;
	}
	return t[x]=find(t[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	t[a]=t[b];
}
int main(){
	cin>>n>>m;
	init();
	int z,x,y;
	for(int i=0;i<m;++i){
		cin>>z>>x>>y;
		if(z==1){
			merge(x,y);
		}
		else{
			if(find(x)==find(y)){
				cout<<"Y"<<endl;
			}
			else{
				cout<<"N"<<endl;
			}
		}
	}
	return 0;
}
