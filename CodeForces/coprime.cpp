#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}
int main()
{
	ll l,r;
	cin>>l>>r;
	bool found=false;
	ll i;
	for(i=l;i<=r-2;i++)
	{
		if(gcd(i,i+1)==1 && gcd(i+1,i+2)==1 && gcd(i,i+2)!=1)
		{
			found=true;
			break;
		}
	}
	if(found) cout<<i<<" "<<i+1<<" "<<i+2<<endl;
	else cout<<-1<<endl;
	return 0;
}