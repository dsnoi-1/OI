#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int t[maxn],d[maxn];
int n,k,ans;
int find(int x){
    if(t[x]!=x){
        int p=t[x];
        t[x]=find(t[x]);
        d[x]=(d[x]+d[p])%3;
    }
    return t[x];
}
void add(int x,int y,int op){
    int xr=find(x),yr=find(y);
    if((xr==yr)&& op!=(d[x]-d[y]+3)%3){
        ++ans;
        return;
    }
    t[xr]=yr;
    d[xr]=(d[y]-d[x]+op+3)%3;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        t[i]=i;
    }
    int op,x,y;
    for(int i=1;i<=k;++i){
        cin>>op>>x>>y;
        --op;
        if(x>n || y>n ||(x==y && op==1)){
            ++ans;
            continue;
        }
        add(x,y,op);
    }
    cout<<ans;
    return 0;
}