#include<bits/stdc++.h>
#define next tail
using namespace std;
const int maxn=1e6+6;
string p,s;
int plen,slen,next[maxn];
void init(){
    next[0]=next[1]=0;
    for(int i=1;i<slen;++i){
        int j=next[i];
        while(j && s[j]!=s[i]){
            j=next[j];
        }
        if(s[i]==s[j]){
            next[i+1]=j+1;
        }
    }
}
void kmp(){
    for(int i=0,j=0;i<plen;++i){
        while(j && p[i]!=s[j]){
            j=next[j];
        }
        if(p[i]==s[j]){
            ++j;
        }
        if(j==slen){
            cout<<i-slen+2<<endl;
        }
    }
}
int main(){
    cin>>p>>s;
    plen=p.size();
    slen=s.size();
    init();
    kmp();
    for(int i=1;i<=slen;++i){
        cout<<next[i]<<' ';
    }
    return 0;
}