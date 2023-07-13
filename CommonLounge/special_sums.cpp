#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);
typedef long long ll;
int main()
{
	io 
	int n;
	cin>>n;
	vector<ll>a(n),b(n);
	for(ll &x:a)
		cin>>x;
	for(ll &x:b)
		cin>>x;
	vector<ll>pre(n+3);// store prefix sum for b
	pre[0]=b[0];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+b[i];
	vector<ll>diff(n+1),sum(n+1);
	diff[0]=a[0]-b[0];
	sum[0]=a[0];
	for(int i=1;i<n;i++)
	{
		diff[i]=max(diff[i-1],a[i]-pre[i]);
		sum[i]=max(sum[i-1],a[i]+pre[i-1]);
	}
	ll ans=a[0];
	for(int i=1;i<n;i++)
	{
		ans=max(ans,max(a[i],diff[i]+a[i]+pre[i-1]));
		ans=max(ans,sum[i-1]+a[i]-pre[i]+pre[n-1]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
here b-->prefix sum array
For any pair (i,j)
 we have 3 possibilities to pair up i and j i.e. i=j , i<j and i>j. 
 If a[] and b[] stores 1st given sequence and prefix sum of second given sequence respectively, then-
For i=j : a[i]
For i<j : a[i] + a[j] + b[j-1] - b[i]
And for i>j : a[i] + a[j] + b[j-1] + b[n] - b[i]
Using these formulas, 1st subtask should be passed.
But for the rest of subtasks, we need to check all possible pairs for a fixed index efficiently.
Let (i,j) be a possible pair. Then-
For i=j : a[i]. [same as O(n^2) formula]
For i<j : we can optimize the given formula for i<j i.e. a[i] + a[j] + b[j-1] - b[i] in O(n^2) solution.
Let j be the endpoint of pair (i,j).
So, we can take the maximized (a[i] - b[i]) for 0<=i<j using dp.
For i>j: O(n^2) formula is a[i] + a[j] + b[j-1] + b[n] - b[i]. 
For this case we have to fix index i and have to find the maximized (a[j] + b[j-1]) using dp.
So, for all j: ans = max(ans , a[j] , (maximized a[j] - b[j] for j)+a[j]+b[j-1] , (maximized a[j] + b[j-1] for j)+a[j]+b[n]-b[j]).
*/
