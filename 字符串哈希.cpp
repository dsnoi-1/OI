#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int pri=131;
ull a[10005],p[1505];
void init(){
	p[0]=1;
	for(int i=1;i<1505;++i){
		p[i]=p[i-1]*pri;
	}
}
void myhash(string s,int k){
	for(int i=0;i<s.size();++i){
		a[k]+=(s[i]-'a')*p[i];
	}
}
int main(){
	int n;
	string s;
	init();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		myhash(s,i);
	}
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;++i){
		if(a[i]!=a[i+1]){
			++ans;
		}
	}
	cout<<ans;
	return 0;
}
