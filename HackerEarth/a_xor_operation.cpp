#include<bits/stdc++.h>
#define int long long
using namespace std;
int solve()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)
		cin>>x;
	int xoval=0LL; // to store the cumulative xor of all the numbers
	unordered_map<int,int>res;
	for(int x:a){
		xoval^=x;
		res[x]=1;
	}
	for(int x:a)
	{
		int val=xoval^x;
		if(res[val]!=1) // if the value not present then return -1
			return -1;
	}
	return xoval; 
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		cout<<solve()<<endl;
	return 0;
}
