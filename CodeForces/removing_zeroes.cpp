#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);
string convert(string& s)
{
	string t="";
	// cout<<endl;
	for(int i=0;i<s.length();i++)
	{
		// cout<<i<<" ";
		int pos=s.find('0');
		if(pos!=string::npos) // copy string before 0
		{
			t+=s.substr(i,pos-i);
			// cout<<t<<" ";
			i=pos;
			s.replace(pos,1,"1"); // for next iteration 
			// cout<<i<<endl;
		}
		else{  // copy the entire string from index i
			t+=s.substr(i,s.length()-i); // consider 211
			i+=(s.length()-i);
			// cout<<i<<" ";
		}
	}
	// cout<<endl<<endl;
	return t;
}
int main()
{
	io
	ll a,b,c;
	cin>>a>>b;
	c=a+b;
	string as,bs,cs;
	as=to_string(a);
	bs=to_string(b);
	cs=to_string(c);
	// cout<<as<<" "<<bs<<" "<<cs<<endl;
	string an=convert(as),bn=convert(bs),cn=convert(cs);
	ll af=stoi(an),bf=stoi(bn),cf=stoi(cn);
	// cout<<af<<" "<<bf<<" "<<cf<<endl;
	if(af+bf==cf)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
