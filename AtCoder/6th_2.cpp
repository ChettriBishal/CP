#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define pb push_back
signed main()
{
	io;
	int n;
	cin>>n;
	vector<pair<int,int>>a,b;
	int sum=LLONG_MAX;
	for(int i=0;i<n;i++)
	{
		int q,r;
		cin>>q>>r;
		if(q+r<sum) 
			sum=q+r;
		a.pb({q,i});
		b.pb({r,i});
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int val=0;
	for(int i=0,j=0;i<n;i++)
	{
		if(a[i].second==b[j].second)
		{
			i--;
			j++;
		}
		else{
			val=max(a[i].first,b[j].first);
			break;
		}
	}
	if(val<sum)
		cout<<val<<endl;
	else
		cout<<sum<<endl;
	return 0;
}
