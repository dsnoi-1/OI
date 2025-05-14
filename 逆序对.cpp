#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*5+5;
int n,a[maxn],b[maxn];
long long sum;
void msort(int l,int r){
	if(l>=r){
		return ;
	}
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int q1=l,q2=mid+1,now=l;
	while(now<=r){
		if(q1>mid){
			b[now++]=a[q2++];
		}
		else if(q2>r){
			b[now++]=a[q1++];
		}
		else if(a[q1]<=a[q2]){
			b[now++]=a[q1++];
		}
		else{
			b[now++]=a[q2++];
			sum+=mid-q1+1;
		}
	}
	for(int i=l;i<=r;++i){
		a[i]=b[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	msort(0,n-1);
	/*for(int i=0;i<n;++i){
		cout<<a[i];
	}*/
	cout<<sum;
	return 0;
}
