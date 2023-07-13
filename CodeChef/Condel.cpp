#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i]; // prefix sum
	}
	int tot=pre[n],cnt=LLONG_MAX;
	for(int i=k;i<=n;i++)
	{
		cnt=min(cnt,pre[i]-pre[i-k]); // shifting window- sum in range of k elements 
	}
	int ans=(cnt*(cnt+1))/2+(tot-cnt);
	cout<<ans<<endl;
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
consider this array 
 0   1   2    3     4
 0   a 	 b    c     d 	
 0   a 	a+b  a+b+c  a+b+c+d ---->prefix sum array
 
So if you calculate the sum of values by k=2 (sliding window)
pre[0]=0;
pre[1]=a;
pre[2]=a+b;
pre[3]=a+b+c;
pre[4]=a+b+c+d;
So the sum in range 
 ar[1] to ar[2]--->pre[2]-pre[2-2]-->(a+b)-0--->a+b
 ar[2] to ar[3]--->pre[3]-pre[3-2]-->(a+b+c)-a--->b+c
 ....
*/
