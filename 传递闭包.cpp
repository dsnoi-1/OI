#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n;
bitset<maxn> a[maxn];
int main(){
	cin>>n;
	getchar();
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			a[i][j]=getchar()-'0';
			if(i==n-1 && j==n-1){
				break;
			}
			getchar();
			//cout<<a[i][j]<<' ';
		}
	}
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			if(a[i][k]){
				a[i]|=a[k];
			}
			/*for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<a[i][j]<<' ';
				}
				cout<<endl;
			}*/
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
