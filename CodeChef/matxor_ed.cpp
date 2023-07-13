#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+m+3]={0};  // difference array storing the count // give n+m+(some extra size) to be on the safe side
	for(int i=1;i<=n;i++)
	{
		int l=i+1; // left most
		int r=i+m; // right most
		a[l]++;
		a[r+1]--; // neutralisation sort of
	}
	int xoro=0;
	for(int x=2;x<=n+m;x++) // here x=i+j in range [2,n+m]
	{
		a[x]+=a[x-1]; // difference array in action
		if(a[x]&1) // if odd then we consider
			xoro^=(x+k); // if we XOR the same number even number of times we get zero.
	}
	cout<<xoro<<endl;
}
int main()
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
