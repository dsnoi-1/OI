#include<bits/stdc++.h>
using namespace std;
long long n,p,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	long long ans=1;
	while(p>0){
		if(p&1)ans=(ans*n)%m;
		p=p/2;
		n=(n*n)%m;
	}
	cout<<ans<<'\n';
	return 0;
}
