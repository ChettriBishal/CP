#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int val=0,i=0;
	while(s[i])
	{
		int k=1;
		bool yes=true;
		while(s[i]==s[i+1])
		{
			k++;
			i++;
			yes=false;
		}
		val=max(val,k);
		if(yes)
			i++;
	}
	cout<<val<<endl;
	return 0;
}