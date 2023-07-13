#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll sumn=n*(n+1)/2;
	ll d=0;
	for(ll i=0;i<n-1;i++)
	{
		ll t;
		cin>>t;
		d+=t;
	}
	cout<<sumn-d<<endl;
	return 0;
}
