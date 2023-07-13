#include<iostream>
#include<map>
using namespace std;
int main()
{
	int k;
	cin>>k;
	k*=2;
	map<char,int>cnt;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='.')
				continue;
			else 
				cnt[ch]++;
		}
	}
	bool en=true;
	for(auto i=cnt.begin();i!=cnt.end();i++)
	{
		if(i->second>k){
			en=false;
			break;
		}
	}
	if(en)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
