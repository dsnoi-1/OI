#include<bits/stdc++.h>
#define map mmm
using namespace std;
int n,m,x,y,d;
int map[410][410];
int cx[]={2,1,-1,-2,-2,-1,1,2},cy[]={1,2,2,1,-1,-2,-2,-1};
queue<int> dfsx,dfsy,dfsd;
inline bool check(int nx,int ny){
	return (nx>0 && nx<=n && ny>0 && ny<=m && map[nx][ny]<0);
}
int main(){
	cin>>n>>m>>x>>y;
	memset(map,-1,sizeof(map));
	map[x][y]=0;
	dfsx.push(x);
	dfsy.push(y);
	dfsd.push(0);
	while(!dfsx.empty()){
		x=dfsx.front();
		y=dfsy.front();
		d=dfsd.front();
		dfsx.pop();
		dfsy.pop();
		dfsd.pop();
		++d;
		for(int i=0;i<8;++i){
			x+=cx[i];
			y+=cy[i];
			if(check(x,y)){
				map[x][y]=d;
				dfsx.push(x);
				dfsy.push(y);
				dfsd.push(d);
			}
			x-=cx[i];
			y-=cy[i];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<map[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
