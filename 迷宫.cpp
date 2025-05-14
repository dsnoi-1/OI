#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,zx,zy;
long long sum;
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
	if(x==fx-1 && y==fy-1){
		/*if(ans==0){
			cout<<"Yes";
		}
		ans=1;*/
		++sum;
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
	a[x][y]='.';
}
int main(){
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	/*for(int i=0;i<n;++i){
		getchar();
		for(int j=0;j<m;++j){
			a[i][j]=getchar();
		}
	}*/
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			a[i][j]='.';
		}
	}
	for(int i=0;i<t;++i){
		cin>>zx>>zy;
		a[zx-1][zy-1]='#';
	}
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	/*for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	dfs(sx-1,sy-1);
	/*if(!ans){
		cout<<"No";
	}*/
	cout<<sum;
	return 0;
}
