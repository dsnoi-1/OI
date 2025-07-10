#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
int a[maxn],logn[maxn];
int st[maxn][20];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
    //cout<<logn[maxn-1];
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        st[i][0]=read();
    }
    for(int i=2;i<=n;++i){
        logn[i]=logn[i>>1]+1;
    }
    for(int i=1;i<=logn[n]+1;++i){
        for(int j=1;j<=n-(1<<i)+1;++j){
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    /*for(int i=1;i<n;++i){
        for(int j=1;j<logn[n]+1;++j){
            cout<<st[i][j]<<' ';
        }
        cout<<endl;
    }*/
    int l,r;
    for(int i=0;i<m;++i){
        l=read();
        r=read();
        int len=logn[r-l+1];
        //cout<<len<<' ';
        printf("%d\n",max(st[l][len],st[r-(1<<len)+1][len]));
    }
    return 0;
}