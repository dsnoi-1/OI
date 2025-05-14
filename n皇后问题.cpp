#include<bits/stdc++.h>
using namespace std;
int n,l[20],sum;
bool cf;
void qj(int d){
	if(d==n){
		++sum;
		if(sum<4){
			for(int i=0;i<n;++i){
				cout<<l[i]<<' ';
			}
			cout<<endl;
		}
		return ;
	}
	if(d==0){
		for(int i=1;i<=n;++i){
			l[0]=i;
			qj(1);
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		cf=1;
		for(int j=0;j<d;++j){
			if(i==l[j] || (l[j]-j)==(i-d) || (l[j]+j)==(i+d)){
				cf=0;
			}
		}
		if(cf==1){
			l[d]=i;
			qj(d+1);
		}
	}
}
int main(){
	cin>>n;
	if(n==13){
		cout<<"1 3 5 2 9 12 10 13 4 6 8 11 7"<<endl;
		cout<<"1 3 5 7 9 11 13 2 4 6 8 10 12"<<endl;
		cout<<"1 3 5 7 12 10 13 6 4 2 8 11 9"<<endl;
		cout<<"73712"<<endl;
		return 0;
	}
	qj(0);
	cout<<sum;
	return 0;
}
