#include<bits/stdc++.h>
using namespace std;
int n,m;
int cx[]={1,0,-1,0},cy[]={0,-1,0,1};
bool ans=0;
char a[105][105];
bool pd(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]=='.'){
		return 1;
	}
	return 0;
}
void dfs(int x,int y){
	//cout<<x<<' '<<y<<endl;
	if(x==n-1 && y==m-1){
		if(ans==0){
			cout<<"Yes";
		}
		ans=1;
		return ;
	}
	a[x][y]='#';
	for(int i=0;i<4;++i){
		x+=cx[i];
		y+=cy[i];
		if(pd(x,y)){
			dfs(x,y);
		}
		x-=cx[i];
		y-=cy[i];
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		getchar();
		for(int j=0;j<m;++j){
			a[i][j]=getchar();
		}
	}
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	dfs(0,0);
	if(!ans){
		cout<<"No";
	}
	return 0;
}
