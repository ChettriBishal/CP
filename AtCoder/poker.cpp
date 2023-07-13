#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
int score(string &s)
{
	vector<int>cnt(10);
	iota(cnt.begin(),cnt.end(),0); // assigns 0 1 2 3 ..
	for(char c: s)
		cnt[c-'0']*=10;
	return accumulate(cnt.begin(),cnt.end(),0);
}
signed main()
{
	int k;
	cin>>k;
	string s,t;
	cin>>s>>t;
	vector<int>cnt(10,k); // all are initialised to k
	for(char c: s+t) // deducting from k what is given to Aoki and Takahasi
		cnt[c-'0']--;
	int win=0;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			s.back()='0'+i;
			t.back()='0'+j;
			if(score(s)<=score(t))
				continue;
			win+=cnt[i]*(cnt[j]-(i==j)); // if Takahasi is winning then it's a possible option
		}
		const int rem=9*k-8;
		cout<<(double)win/(rem*(rem-1))<<endl;
	return 0;
}
