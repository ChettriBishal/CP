#include<bits/stdc++.h> // logic based // but will give tle
using namespace std;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		s=s.substr(1)+s.substr(0,1); // left rotation
		if((bitset<16>(s).to_ulong())%2==0) // converts binary string to decimal
			cnt++;
	}
	cout<<cnt<<endl;
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
/*
********************************this one is clever
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int even=count(s.begin(),s.end(),'0');
		cout<<even<<endl;
	}
	return 0;
}
Cause only those numbers will be even which have 0 at one's place
*/
