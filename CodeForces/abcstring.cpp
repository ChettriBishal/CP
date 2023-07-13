/*
3^x^y gives the exponent which is not x and y ie, 
if the value except x and y =3^x^y
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool solve()
{
	string s;
	cin>>s;
	int x=s[0]-'A';
	int y=s.back()-'A';
	if(x==y)
		return false;
	vector<int>d(3);
	d[x]=1; // opening braces
	d[y]=-1; // closing braces
	if(count(s.begin(),s.end(),x+'A')==s.length()/2)
		d[3^x^y]=-1; // if the no of opening brackets is half then 'c' type must be closing
	else
		d[3^x^y]=1; // if not then 'c' type has to be opening 
	int bal=0;
	for(char c:s){
		bal+=d[c-'A'];
		if(bal<0)
			return false;
	}
	return bal==0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve()?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
