#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)						
		cin>>x;
	int inv=0,equal=0;
	for(int i=0;i+1<n;i++)
	{
		if(a[i]>a[i+1])
			inv++;
		if(a[i]==a[i+1])
			equal++;
	}
	int res=inv;
	if(res>n/2)
	{
		res=n-res;
		res-=equal; //see below
	}
	cout<<res<<endl;
	if(inv>n/2) // reverse state XORing
	{
		cout<<3<<" "<<n<<" "<<(1LL<<30)-1<<endl;
		for(int i=0;i<n;i++)
			a[i]^=(1LL<<30)-1;
	}
	for(int i=n-1;i>0;i--)
	{
		if(a[i]<a[i-1])
			cout<<2<<" "<<i+1<<" "<<(1LL<<30)-1<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
/*
XOR operation can change the order of inequality not equality condition.
So (n-1-cnt) is count of arr[i-1]>=arr[i]. 
So according to editorial…we have to add the diff in next term… but, here k>0. 
So we cannot add 0 to next number. so we have to minus those count of arr[i-1]==arr[i].
Now we will get correct count of arr[i-1]>arr[i]
*/
