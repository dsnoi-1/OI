#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,lc,rc,lsum,rsum;
}bst[10005];
int sum,root=1;
int newn(int val){
	bst[++sum].v=val;
	return sum;
}
void init(){
	newn(-INT_MAX);
	newn(INT_MAX);
	bst[1].rc=2;
	bst[1].rsum=1;
}
void ad(int &p,int val){
	if(p==0){
		p=newn(val);
		return ;
	}
	if(val<bst[p].v){
		++bst[p].lsum;
		ad(bst[p].lc,val);
	}
	else{
		++bst[p].rsum;
		ad(bst[p].rc,val);
	}
}
int pm(int p,int val,int ans){
	if(p==0){
		return ans;
	}
	if(bst[p].v>=val){
		return pm(bst[p].lc,val,ans);
	}
	else{
		return pm(bst[p].rc,val,bst[p].lsum+ans+1);
	}
}
int cx(int p,int n){
	if(p==0){
		return INT_MAX;
	}
	if(bst[p].lsum+1==n){
		return bst[p].v;
	}
	if(bst[p].lsum+1>n){
		return cx(bst[p].lc,n);
	}
	return cx(bst[p].rc,n-1-bst[p].lsum);
}
int qq(int now,int x,int ans){
	if(now==0){
		return ans;
	}
	if(bst[now].v<x){
		return qq(bst[now].rc,x,bst[now].v);
	}
	else{
		return qq(bst[now].lc,x,ans);
	}
}
int hj(int now,int x,int ans){
	if(now==0){
		return ans;
	}
	if(bst[now].v<=x){
		return hj(bst[now].rc,x,ans);
	}
	else{
		return hj(bst[now].lc,x,bst[now].v);
	}
}
int main(){
	init();
	int q,op,x;
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>op>>x;
		if(op==1){
			cout<<pm(root,x,0)<<endl;
		}
		else if(op==2){
			cout<<cx(root,x+1)<<endl;
		}
		else if(op==3){
			cout<<qq(root,x,-INT_MAX)<<endl;
		}
		else if(op==4){
			cout<<hj(root,x,INT_MAX)<<endl;
		}
		else{
			ad(root,x);
		}
	}
	return 0;
}
