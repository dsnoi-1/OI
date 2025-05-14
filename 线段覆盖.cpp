#include<bits/stdc++.h>
using namespace std;
int n,sum,lb;
struct bs{
	int a,b;
}j[1000005];
bool bj(bs f,bs l){
	return f.b<l.b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>j[i].a>>j[i].b;
	}
	sort(j,j+n,bj);
	sum=1;
	lb=j[0].b;
	for(int i=1;i<n;++i){
		if(j[i].a>=lb){
			++sum;
			lb=j[i].b;
		}
	}
	cout<<sum;
	return 0;
}
