#include<bits/stdc++.h>
using namespace std;
const int MAXL=5005;
struct Bint{
	int len;
	int num[MAXL];
	Bint operator = (const char *c){
		memset(num,0,sizeof(num));
		int n=strlen(c),j=1,k=1;
		for(int i=1;i<=n;++i){
			if(k==10000){
				k=1;
				++j;
			}
			num[j]+=k*(c[n-i]-'0');
			k*=10;
		}
		len=j;
		return *this;
	}
	Bint operator = (int a){
		char c[MAXL];
		sprintf(c,"%d",a);
		return *this=c;
	};
	Bint(){
		memset(num,0,sizeof(num));
		len=1;
	}
	
	bool operator < (const Bint &)const;

	Bint operator + (const Bint &)const;
	Bint operator - (const Bint &)const;
	Bint operator * (const Bint &)const;
	Bint operator / (const long long &)const;
};

bool Bint::operator < (const Bint &b)const{
	if(len!=b.len){
		//cout<<"len";
		return len<b.len;
	}
	for(int i=len;i>0;--i){
		if(num[i]!=b.num[i]){
			//cout<<"n"<<num[i]<<' '<<b.num[i]<<"e"<<endl;
			return num[i]<b.num[i];
		}
	}
	return false;
}

Bint Bint::operator + (const Bint &b)const{
	Bint c;
	c.len=max(len,b.len);
	for(int i=1;i<=c.len;++i){
		c.num[i]+=num[i]+b.num[i];
		if(c.num[i]>=10000){
			c.num[i]-=10000;
			++c.num[i+1];
		}
	}
	if(c.num[c.len+1]>0){
		++c.len;
	}
	return c;
}

Bint Bint::operator - (const Bint &b)const{
	Bint c;
	c.len=max(len,b.len);
	for(int i=1;i<=c.len;++i){
		c.num[i]+=num[i]-b.num[i];
		if(c.num[i]<0){
			c.num[i]+=10000;
			--c.num[i+1];
		}
	}
	while(c.num[c.len]==0 && c.len>0){
		--c.len;
	}
	return c;
}

Bint Bint::operator * (const Bint &b)const{
	Bint c;
	c.len=len+b.len;
	for(int i=1;i<=len;++i){
		for(int j=1;j<=b.len;++j){
			c.num[i+j-1]+=num[i]*b.num[j];
			c.num[i+j]+=c.num[i+j-1]/10000;
			c.num[i+j-1]%=10000;
		}
	}
	while(!c.num[c.len] && c.len>1){
		--c.len;
	}
	return c;
}

Bint Bint::operator / (const long long &b)const{
	Bint c;
	c.len=len;
	long long res=0;
	for(int i=len;i>0;--i){
		long long tmp=res*10000+num[i];
		c.num[i]=tmp/b;
		res=tmp%b;
	}
	c.num[0]=0;
	while(!c.num[c.len] && c.len>1){
		--c.len;
	}
	return c;
}

istream &operator >> (istream & in,Bint &a){
	char s[MAXL*4];
	in>>s;
	a=s;
	return in;
}

ostream &operator << (ostream &o,Bint &a){
	o<<a.num[a.len];
	for(int i=a.len-1;i>0;--i){
		o.width(4);
		o.fill('0');
		o<<a.num[i];
	}
	return o;
}

int main(){
	Bint a,c;
	int b;
	cin>>a>>b;
	c=a/b;
	cout<<c;
	return 0;
} 
