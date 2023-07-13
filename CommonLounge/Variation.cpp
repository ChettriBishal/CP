#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int &x:a)
		cin>>x;
	sort(a.begin(),a.end()); // sorting for a reason
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int ind=lower_bound(a.begin(),a.end(),k+a[i])-a.begin();
		cnt+=(n-ind);
	}
	cout<<cnt<<endl;
}
/*
All those values which are equal to or greater than k+a[i] pair will contribute a pair with a[i] such that a[j]-a[i]>=k......j>i
j belongs to the range of values of index starting from (values>=a[i]+k).......ie ranges from lower_bound(a[i]+k) till last index (cause it's already sorted)
Logical:
say a  <  b  <  c  <  d  <  e  <  f  <  g  <  h  are the elements and a,c are first pair such that c-a>=k
    0     1     2     3     4     5     6     7   
then all the values lying above it will also make such pair with a...ie
d-a>k
e-a>k
f-a>k
g-a>k
h-a>k
with respect to a the count of such pairs is: 6= n-ind = 8-2
*/
