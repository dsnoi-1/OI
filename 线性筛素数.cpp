#include<bits/stdc++.h>
using namespace std;
const int maxn=100010000;
int n,p[1000005],sum,q,a;
bool vis[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			p[sum++]=i;
			//cout<<p[sum-1]<<' ';
		}
		for(int j=0;j<sum && i*p[j]<=n;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>a;
		cout<<p[a-1]<<'\n';
	}
	return 0;
}
