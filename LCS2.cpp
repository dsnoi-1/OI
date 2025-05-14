#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[3005][3005],maxn,maxi,maxj;
char jl[3005][3005];
stack<char> aaaa;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();++i){
		for(int j=0;j<t.size();++j){
			if(s[i]==t[j]){
				dp[i+1][j+1]=dp[i][j]+1;
				jl[i+1][j+1]='x';
				if(dp[i+1][j+1]>maxn){
					maxn=dp[i+1][j+1];
					maxi=i+1;
					maxj=j+1;
				}
			}
			else{
				if(dp[i][j+1]>dp[i+1][j]){
					dp[i+1][j+1]=dp[i][j+1];
					jl[i+1][j+1]='s';
				}
				else{
					dp[i+1][j+1]=dp[i+1][j];
					jl[i+1][j+1]='z';
				}
			}
		}
	}
	/*for(int i=1;i<=s.size();++i){
		for(int j=1;j<=t.size();++j){
			cout<<jl[i][j];
		}
		cout<<endl;
	}*/
	int i=maxi,j=maxj;
	while(1){
		//cout<<jl[i][j]<<endl;
		if(i==0 || j==0){
			break;
		}
		/*if(i==1 || j==1){
			cout<<s[i-1];
		}*/
		if(jl[i][j]=='x'){
			aaaa.push(s[i-1]);
			--i;
			--j;
		}
		else if(jl[i][j]=='s'){
			//cout<<jl[i][j]<<endl;
			//cout<<'s'<<i;
			--i;
			//cout<<i;
		}
		else if(jl[i][j]=='z'){
			//cout<<jl[i][j]<<endl;
			//cout<<'z'<<j;
			--j;
			//cout<<j;
		}
	}
	while(!aaaa.empty()){
		cout<<aaaa.top();
		aaaa.pop();
	}
	return 0;
}
