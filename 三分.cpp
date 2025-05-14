#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int n;
double l,r,a[15];
double f(double x){
	double s=0;
	for(int i=0;i<=n;++i){
		s=s*x+a[i];
	}
	return s;
}
int main(){
	cin>>n>>l>>r;
	for(int i=0;i<=n;++i){
		cin>>a[i];
	}
	//cout<<f(-0.414);
	double m1,m2;
	while(r-l>eps){
		m1=l+(r-l)/3.0;
		m2=r-(r-l)/3.0;
		//cout<<m1<<' '<<m2<<' '<<f(m1)<<' '<<f(m2)<<endl;
		if(f(m1)>f(m2)){
			r=m2;
		}
		else{
			l=m1;
		}
	}
	cout<<l;
	return 0;
}
