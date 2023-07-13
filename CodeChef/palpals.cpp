#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
	string s;
	cin>>s;
	int a=0,b=0;
	vector<int>f(26);
	for(int i=0;i<s.length();i++)
		f[s[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		a+=f[i]/2; // for number of pairs 
		b+=f[i]%2; // residuary values excluding the pairs 
	}               // eg f[i]=5 then a=2 (two pairs) and b=1 extra letter
	if(a>=b)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
int main()
{
	io;
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}