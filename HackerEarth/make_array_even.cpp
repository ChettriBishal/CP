#include<bits/stdc++.h>
#define int long long
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int len=0,res=0;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		if(val&1)
			len++; // if val is odd
		else{
			res+=(len/2)+2*(len&1);  // 2*(len&1) handles for cases if len is odd
			len=0;
		}
	}
	res+=(len/2)+2*(len&1);
	cout<<res<<endl;
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
We will gather all the segments which are odd. Obviously we don't need to transform the even numbers.Fron now we will consider an segment of odd numbers:

If its length is even we can easily convert it into even by (length/2) operations as we will choose every element once.

If length is odd for length-1 we will go to above part and for the last element we will need 2 operation with even number.

Case: odd even

After first operation: odd odd

After second operation: even even
*/
