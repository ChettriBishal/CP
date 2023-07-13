#include<bits/stdc++.h> // another method 
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int i=0;
	while(1)
	{
		i=s.find("party",i); // initial index of party if found
		if(i==string::npos) // if not found
			break;
		s.replace(i,5,"pawri"); // three arguments
		i+=5;
	}
	cout<<s<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
