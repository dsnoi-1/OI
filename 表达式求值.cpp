#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<int> q;
stack<char> op;
void printff(stack<int> &a){
    stack<int> b;
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    while(!b.empty()){
        a.push(b.top());
        cout<<b.top()<<' ';
        b.pop();
    }
    cout<<endl;
}
bool bigger(char a,char b){
    if(a=='(' || b=='('){
        return 1;
    }
    if((a=='*'||a=='/')&&(b=='+'||b=='-')){
        return 1;
    }
    return 0;
}
void solve(){
    int b=q.top();
    q.pop();
    int a=q.top();
    q.pop();
    int num;
    switch(op.top()){
        case '+':num=a+b;break;
        case '-':num=a-b;break;
        case '*':num=a*b;break;
        case '/':num=a/b;break;
    }
    op.pop();
    q.push(num);
}
int main(){
    //cin>>s;
    char b;
    while(cin.get(b)){
        if(b!='\n'){
            s+=b;
        }
    }
    s="("+s+")";
    n=s.size();
    int i=0;
    while(i<n){
        if(s[i]==' '){
            ++i;
            continue;
        }
        if(s[i]>='0' && s[i]<='9'){
            int num=0;
            while(i<n && s[i]>='0' && s[i]<='9'){
                num*=10;
                num+=s[i]-'0';
                ++i;
            }
            //cout<<num<<endl;
            q.push(num);
        }
        else{
            char nop=s[i++];
            //cout<<nop<<endl;
            if(nop==')'){
                while(op.top()!='('){
                    solve();
                }
                if(!op.empty() && op.top()=='('){
                    op.pop();
                }
            }
            while(1){
                if(op.empty()){
                    op.push(nop);
                    break;
                }
                if(bigger(nop,op.top())){
                    op.push(nop);
                    break;
                }
                solve();
            }
        }
        //printff(q);
    }
    cout<<q.top();
    return 0;
}