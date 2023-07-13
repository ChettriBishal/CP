#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
bool is_prime(ll x){
  if(x<=1) return false;
  for(ll i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}

void solve()
{
	string s;
	cin>>s;
	string s2="party",s3="pawri",s4="";
	int j=0,i=0;
	while(i<s.length())
	{
		bool in=true;
		if(s[i]=='p')
		{
			if(i+4<s.length()){
				if(s.substr(i,5)==s2){
					s4+=s3;
					i+=4;
					in=false;
				}
			}
		}
		if(in)
			s4+=s[i];
		//cout<<i<<" "<<s4<<endl;
		i++;
	}
	cout<<s4<<endl;
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
