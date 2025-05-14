#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,op,x,size,a[maxn];
void up(int k){
	int pa=k;
	while(pa>1 && a[pa]<a[pa/2]){
		swap(a[pa],a[pa/2]);
		pa/=2;
	}
}
void down(int k){
	int pa=k;
	int ch;
	while(pa*2<=size){
		ch=pa*2;
		if(pa*2<size && a[ch+1]<a[ch]){
			++ch;
		}
		if(a[ch]>=a[pa]){
			break;
		}
		swap(a[ch],a[pa]);
		pa=ch;
	}
}
void push(int k){
	a[++size]=k;
	up(size);
}
void pop(){
	a[1]=a[size];
	--size;
	down(1);
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>op;
		if(op==1){
			cin>>x;
			push(x);
		}
		else if(op==2){
			cout<<a[1]<<endl;
		}
		else{
			pop();
		}
	}
	return 0;
}
