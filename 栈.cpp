#include<bits/stdc++.h>
using namespace std;
int t,n;
string x;
string cg;
stack<string> a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n;
		for(int j=0;j<n;++j){
			cin>>cg;
			if(cg=="push"){
				cin>>x;
				a.push(x);
			}
			else if(cg=="pop"){
				if(a.empty()){
					cout<<"Empty"<<endl;
				}
				else{
					a.pop();
				}
			}
			else if(cg=="query"){
				if(a.empty()){
					cout<<"Anguei!"<<endl;
				}
				else{
					cout<<a.top()<<endl;
				}
			}
			else if(cg=="size"){
				cout<<a.size()<<endl;
			}
		}
		while(!a.empty()){
			a.pop();
		}
	}
	return 0;
}
