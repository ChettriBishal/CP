#include<iostream>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll ex_pow(ll a,ll b)
{
	if(b==0)
		return 1;
	ll res=(ll)ex_pow(a,b/2LL);
	if(b&1)
		return ((res%mod)*(res%mod)*(a%mod))%mod;
	else
		return ((res%mod)*(res%mod))%mod;
}
int main()
{
	ll n;
	cin>>n;
	ll val=ex_pow(2,n);
	cout<<val<<endl;
	return 0;
}
