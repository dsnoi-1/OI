#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,q,m;
ll a[maxn],t[maxn<<2],tag1[maxn<<2],tag2[maxn<<2];
//tag1记录乘,tag2记录加
inline int ls(int p){
    return p<<1;
}
inline int rs(int p){
    return p<<1|1;
}
inline void addtag1(int p,int pl,int pr,ll k){
    tag1[p]=(tag1[p]*k)%m;
    tag2[p]=(tag2[p]*k)%m;
    t[p]=(t[p]*k)%m;
}
inline void addtag2(int p,int pl,int pr,ll k){
    tag2[p]=(tag2[p]+k)%m;
    t[p]=(t[p]+(pr-pl+1)*k)%m;
}
inline void pushup(int p){
    t[p]=(t[ls(p)]+t[rs(p)])%m;
}
void pushdown(int p,int pl,int pr){
    int mid=pl+((pr-pl)>>1);
    addtag1(ls(p),pl,mid,tag1[p]);
    addtag1(rs(p),mid+1,pr,tag1[p]);
    tag1[p]=1;
    addtag2(ls(p),pl,mid,tag2[p]);
    addtag2(rs(p),mid+1,pr,tag2[p]);
    tag2[p]=0;
}
void build(int p,int pl,int pr){
    tag1[p]=1;
    if(pl==pr){
        t[p]=a[pl]%m;
        return;
    }
    int mid=pl+((pr-pl)>>1);
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void update1(int l,int r,ll k,int p,int pl,int pr){
    if(l<=pl && pr<=r){
        addtag1(p,pl,pr,k);
        return;
    }
    pushdown(p,pl,pr);
    int mid=pl+((pr-pl)>>1);
    if(l<=mid){
        update1(l,r,k,ls(p),pl,mid);
    }
    if(r>mid){
        update1(l,r,k,rs(p),mid+1,pr);
    }
    pushup(p);
}
void update2(int l,int r,ll k,int p,int pl,int pr){
    if(l<=pl && pr<=r){
        addtag2(p,pl,pr,k);
        return;
    }
    pushdown(p,pl,pr);
    int mid=pl+((pr-pl)>>1);
    if(l<=mid){
        update2(l,r,k,ls(p),pl,mid);
    }
    if(r>mid){
        update2(l,r,k,rs(p),mid+1,pr);
    }
    pushup(p);
}
ll query(int l,int r,int p,int pl,int pr){
    if(l<=pl && pr<=r){
        return t[p];
    }
    pushdown(p,pl,pr);
    int mid=pl+((pr-pl)>>1);
    ll ans=0;
    if(l<=mid){
        ans=(ans+query(l,r,ls(p),pl,mid))%m;
    }
    if(r>mid){
        ans=(ans+query(l,r,rs(p),mid+1,pr))%m;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n>>q>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);
    int op,x,y;
    ll k;
    for(int i=1;i<=q;++i){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update1(x,y,k%m,1,1,n);
        }       
        else if(op==2){
            cin>>x>>y>>k;
            update2(x,y,k%m,1,1,n);
        }
        else{
            cin>>x>>y;
            cout<<query(x,y,1,1,n)<<endl;
        }
    }
    return 0;
}