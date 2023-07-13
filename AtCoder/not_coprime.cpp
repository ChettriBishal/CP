#include<bits/stdc++.h>
typedef long long ll;
#define rep(k,i,n) for(int i=k;i<n;i++)
using namespace std;
bool is_prime(ll x){
  if(x<=1) return false;
  for(ll i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)
		cin>>x;
	vector<int>pr;
	rep(2,i,51)
		if(is_prime(i))
			pr.push_back(i);
	ll res=LLONG_MAX;
	rep(0,i,(1<<15)) // generating all subsets
	{
		ll val=1;
		rep(0,j,15)
			if(i&(1<<j))
				val*=pr[j];
		bool flag=true;
		rep(0,i,n)
		{
			if(gcd(val,a[i])==1)
			{
				flag=false;
				break;
			}
		}
		res=flag?min(res,val):res;
	}
	cout<<res<<endl;
}
