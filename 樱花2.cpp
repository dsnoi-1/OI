#include<bits/stdc++.h>
using namespace std;
int hh1,mm1,hh2,mm2,n,s,cnt,a;
int t1[10005],c1[10005],p1[10005];
int t[90000],c[90000],f[10005];
int main(){
	scanf("%d:%d %d:%d %d",&hh1,&mm1,&hh2,&mm2,&n);
	ios::sync_with_stdio(0);
	cin.tie(0);
	s=(hh2-hh1)*60+(mm2-mm1);
	for(int i=1;i<=n;++i){
		cin>>t1[i]>>c1[i]>>p1[i];
		if(p1[i]==0){
			p1[i]=s/t1[i];
		}
	}
	for(int i=1;i<=n;++i){
		a=1;
		while(p1[i]>a){
			t[++cnt]=t1[i]*a;
			c[cnt]=c1[i]*a;
			//cout<<t[cnt]<<' '<<c[cnt]<<endl;
			p1[i]-=a;
			a*=2;
		}
		t[++cnt]=t1[i]*p1[i];
		c[cnt]=c1[i]*p1[i];
		//cout<<t[cnt]<<' '<<c[cnt]<<endl;
	}
	for(int i=1;i<=cnt;++i){
		for(int j=s;j>=t[i];--j){
			f[j]=max(f[j],f[j-t[i]]+c[i]);
		}
	}
	cout<<f[s];
	return 0;
}
