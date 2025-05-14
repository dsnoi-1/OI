#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],q[200005],minn,ans=-1000000000000000ll;
int main(){
	//cout<<minn<<ans;
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		ans=max(ans,a[i]);
		if(i==0){
			q[i]=a[i];
		}
		else{
			q[i]=a[i]+q[i-1];
		}
	}
	if(ans<=0){
		cout<<ans;
		return 0;
	}
	ans=-1000000000000000ll;
	minn=0;
	for(int i=0;i<n;++i){
		ans=max(ans,q[i]-minn);
		minn=min(minn,q[i]);
	}
	cout<<ans;
	return 0;
}
