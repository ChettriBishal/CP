#include<iostream> // agressive cows 
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
bool check(vector<ll>a, ll x,ll c) // check if the gap satisfies 
{
	ll n_cows=1,prev=a[0];
	for(ll i=1;i<a.size();i++)
	{
		if(a[i]-prev>=x)
		{
			if(++n_cows==c) return true;
			prev=a[i]; // updating the previous position
		}
	}
	return false;
}
void solve()
{
	ll n,c;
	cin>>n>>c;
	vector<ll>a(n);
	for(ll &x:a)
		cin>>x;
	sort(a.begin(),a.end());
	ll lmd;
	ll s=0,e=a[n-1]-a[0]; //s--->start    e--->end
	ll mid;
	// cout<<endl;
	while(s<=e)
	{
		mid=(s+e)/2;
		// cout<<s<<" "<<mid<<" "<<e<<endl;
		if(check(a,mid,c))
		{
			// cout<<"if"<<endl;
			s=mid+1;
			lmd=mid;
		}
		else{
			// cout<<"else"<<endl;
			e=mid-1;
		}
		// cout<<s<<" "<<mid<<" "<<e<<endl<<endl;
	}
	cout<<lmd<<endl;
	
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
