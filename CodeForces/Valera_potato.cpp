#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	ll y,k,n,x=1;
	cin>>y>>k>>n;
	vector<ll>mul;
	for(ll i=1;i*k<=n;i++)
		mul.pb(i*k);
	auto indi=lower_bound(mul.begin(),mul.end(),y+1); // nearest multiple to y+x
	//ll ind=lower_bound(mul.begin(),mul.end(),y+1)-mul.begin();
	if(indi==mul.end()) // if not found ie not available 
		cout<<-1;
	else
		for(auto i=indi;i!=mul.end();i++)
			cout<<*i-y<<" ";
	return 0;
}
/*
We'll consider only those multiples starting with the minimum value of y+x 
if no such value exists then it's not possible
*/
