#include<bits/stdc++.h>
using namespace std;
void solve()
{
	stack<char>tr;
	string s;
	cin>>s;
	string ans="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') {}
		else if(isalpha(s[i]))
			ans+=s[i];
		else{
			if(s[i]!=')')
			tr.push(s[i]);
		}
		if(s[i]==')')
		{
			ans+=tr.top();
			tr.pop();
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
