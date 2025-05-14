#include<bits/stdc++.h>
using namespace std;
int t,m,z[105],j[105],f[1005];
int main(){
	cin>>t>>m;
	for(int i=0;i<m;++i){
		cin>>z[i]>>j[i];
		for(int k=t;k>=z[i];--k){
			f[k]=max(f[k-z[i]]+j[i],f[k]);
		}
	}
/*	
	for(int i=0;i<=t;++i){
		cout<<f[i]<<' ';
	}
	cout<<endl;
	*/
	cout<<f[t];
	return 0;
}
