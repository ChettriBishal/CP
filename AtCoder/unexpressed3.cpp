#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
signed main()
{
	int n;
	cin>>n;
	set<int>a;
	for(int i=2;i*i<=n;i++)
	{
		int val=i*i;
		while(val<=n)
		{
			a.insert(val);
			val*=i;
		}
	}
	cout<<n-a.size()<<endl;
	return 0;
}
