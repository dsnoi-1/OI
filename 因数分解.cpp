#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (long long i=2; i*i<=n; i++){
		int c=0;
		while (n%i==0){
			c++;
			n/=i;
		}
		if (c>0) {
			cout<<i;
			if (c>1) cout<<"^"<<c;
			if (n!=1) cout<<" * ";
		}
	}
	if (n>1) cout<<n;
	return 0;
}
