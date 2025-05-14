#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005],maxn,sum;
char zf;
string s,t,ans;
int main(){
	cin>>s>>t;
	if(t.size()>s.size()){
		swap(s,t);
	}
	for(int i=0;i<s.size();++i){
		maxn=0;
		zf='';
		for(int j=0;j<t.size();++j){
			if(s[i]==t[j]){
				a[j]=maxn+1;
				//cout<<j<<a[j]<<t[j]<<endl;
			}
			if(maxn<b[j]){
				zf=t[j];
				maxn=b[j];
			}
		}
		memcpy(b,a,sizeof(a));
	}
	
	maxn=0;
	/*for(int i=0;i<s.size();++i){
		if(a[i]>maxn){
			maxn=a[i];
			cout<<i<<t[i];
		}
	}*/
	cout<<endl;
	return 0;
}
