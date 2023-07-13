#include<iostream>
using namespace std;
typedef long long ll;
ll remove(ll n)
{
	ll ret=0;
	ll t=1;
	while(n)
	{
		int k=n%10;
		if(k){     // for non-zero contributions
			ret+=(k*t);
			t*=10;
		}
		n/=10;
	}
	return ret;
}
int main()
{
	ll a,b,c;
	cin>>a>>b;
	c=a+b;
	a=remove(a);
	b=remove(b);
	c=remove(c);
	if(a+b==c)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
