#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int s,f,l,d;
char c;
int main(){
	while(c=getchar()){
		if(c=='@'){
			cout<<a.top();
			return 0;
		}
		if(c=='.'){
			a.push(s);
			s=0;
		}
		else if(c>='0' && c<='9'){
			s*=10;
			s+=c-'0';
		}
		else{
			f=a.top();
			a.pop();
			l=a.top();
			a.pop();
			if(c=='+'){
				d=f+l;
			}
			if(c=='-'){
				d=l-f;
			}
			if(c=='*'){
				d=f*l;
			}
			if(c=='/'){
				d=l/f;
			}
			a.push(d);
			//cout<<d<<' ';
		}
	}
	return 0;
}
