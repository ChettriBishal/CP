#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	int moves=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]<a[i])
		{
			moves+=a[i]-a[i+1];
			a[i+1]+=a[i]-a[i+1];
		}
	}
	cout<<moves<<endl;
	return 0;

}