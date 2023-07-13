#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int>>a;
	int val=0;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		a.push_back({val,i});
	}
	vector<int>b(n); // to store the jumps 
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(a.begin(),a.end());
	int prev=a[0].second; // to store the previous position
	int hits=0;
	for(int i=1;i<n;i++)
	{
		int cur=a[i].second;
		int j=cur; // to access the jump value for the current frog
		// while(cur<=prev) // if the current position of frog (with higher weight) is less than the position of previous frog (less weight)
		// {
		// 	cur+=b[j];
		// 	hits++;
		// }
		// prev=cur; // updating the value of prev
		int k=cur<=prev?(prev-cur+b[j])/b[j]:0;
		hits+=k;
		prev=cur+(k*b[j]);
	}
	cout<<hits<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
