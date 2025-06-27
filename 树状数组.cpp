#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int tree[maxn];
inline int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    if(x==0){
        return 0;
    }
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
void init1(){
    int temp,next;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>temp;
        tree[i]+=temp;
        next=i+lowbit(i);
        if(next<=n){
            tree[next]+=tree[i];
        }
    }
}
void init2(){
    int temp;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>temp;
        update(i,temp);
        update(i+1,-temp);
    }
}
int main(){
    //单点修改，区间查询
    /*init1();
    int op,x,y;
    for(int i=0;i<m;++i){
        cin>>op>>x>>y;
        if(op==1){
            update(x,y);
        }
        else{
            cout<<sum(y)-sum(x-1)<<endl;
        }
    }*/

    //区间修改，单点查询
    int op,x,y,k;
    init2();
    for(int i=0;i<m;++i){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update(x,k);
            update(y+1,-k);
        }
        else{
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }
    return 0;
}