#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
long long a[maxn],tag[maxn<<2],t[maxn<<2];
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
inline void pushup(int p){
    t[p]=t[ls(p)]+t[rs(p)];
}
void build(int p,int pl,int pr){
    //cout<<p<<' '<<pl<<' '<<pr<<endl;
    if(pl==pr){
        t[p]=a[pl];
        return;
    }
    int mid=pl+((pr-pl)>>1);
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
inline void addtag(int p,int pl,int pr,long long k){
    tag[p]+=k;
    t[p]+=(pr-pl+1)*k;
}
inline void pushdown(int p,int pl,int pr){
    if(tag[p]){
        int mid=pl+((pr-pl)>>1);
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(int l,int r,long long k,int p,int pl,int pr){
    if(l<=pl && pr<=r){
        addtag(p,pl,pr,k);
        return;
    }
    pushdown(p,pl,pr);
    int mid=pl+((pr-pl)>>1);
    if(l<=mid){
        update(l,r,k,ls(p),pl,mid);
    }
    if(r>mid){
        update(l,r,k,rs(p),mid+1,pr);
    }
    pushup(p);
}
long long query(int l,int r,int p,int pl,int pr){
    if(l<=pl && pr<=r){
        return t[p];
    }
    pushdown(p,pl,pr);
    int mid=pl+((pr-pl)>>1);
    long long ans=0;
    if(l<=mid){
        ans+=query(l,r,ls(p),pl,mid);
    }
    if(r>mid){
        ans+=query(l,r,rs(p),mid+1,pr);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);
    int op,x,y;
    long long k;
    for(int i=0;i<m;++i){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update(x,y,k,1,1,n);
        }
        else{
            cin>>x>>y;
            cout<<query(x,y,1,1,n)<<endl;
        }
    }
    return 0;
}