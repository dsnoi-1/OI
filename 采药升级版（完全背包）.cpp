#include<bits/stdc++.h>
using namespace std;
long long t,m,s[10005],p[10005],f[10000005]; 
int main(){
	cin>>t>>m;
	for(int i=0;i<m;++i){
		cin>>s[i]>>p[i];
		for(int j=s[i];j<=t;++j){
			f[j]=max(f[j],f[j-s[i]]+p[i]);
		}
	}
	cout<<f[t];
	return 0;
}
