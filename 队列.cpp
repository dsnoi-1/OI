#include<bits/stdc++.h>
using namespace std;
int n;
string x;
string cg;
queue<string> a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int j=0;j<n;++j){
		cin>>cg;
		if(cg=="1"){
			cin>>x;
			a.push(x);
		}
		else if(cg=="2"){
			if(a.empty()){
				cout<<"ERR_CANNOT_POP"<<endl;
			}
			else{
				a.pop();
			}
		}
		else if(cg=="3"){
			if(a.empty()){
				cout<<"ERR_CANNOT_QUERY"<<endl;
			}
			else{
				cout<<a.front()<<endl;
			}
		}
		else if(cg=="4"){
			cout<<a.size()<<endl;
		}
	}
	while(!a.empty()){
		a.pop();
	}
	return 0;
}
