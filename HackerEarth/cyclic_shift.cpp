#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	char d;
	cin>>n>>m>>d;
	string s=bitset<16>(n).to_string();
	cout<<s<<endl; //actual string
	m%=s.size(); // cause the cycles start repeating after one traversal
	if(d=='L') // left cyclic shift
		s=s.substr(m)+s.substr(0,m);
	else        // right cyclic shift
		s=s.substr(s.size()-m)+s.substr(0,s.size()-m);
	cout<<s<<endl;  //shifted string
	cout<<bitset<16>(s).to_ulong()<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
