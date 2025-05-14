#include<bits/stdc++.h>
using namespace std;
typedef double ld;
int n,t;
ld ans;
struct b1{
	long double m,v,j;
}b[105];
bool dy(b1 f,b1 l){
	return f.j>l.j;
}
int main(){
	cin>>n>>t;
	for(int i=0;i<n;++i){
		cin>>b[i].m>>b[i].v;
		b[i].j=b[i].v/b[i].m;
	}
	sort(b,b+n,dy);
	for(int i=0;i<n;++i){
		if(b[i].m==t){
			ans+=b[i].v;
			break;
		}
		else if(b[i].m<t){
			ans+=b[i].v;
			t-=b[i].m;
		}
		else{
			ans+=b[i].j*t;
			break;
		}
	}
	//cout<<ans;
	printf("%.2f",ans);
	return 0;
}
