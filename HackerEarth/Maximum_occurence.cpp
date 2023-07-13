/* Maximum Occurence HackerEarth*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
    getline(cin,s);
	unordered_map<char,int>um;
	for(int i=0;i<s.size();i++){
        um[s[i]]++;
	}
	int res = INT_MIN;
	char g;
	for(auto &x: um){
		if(x.second > res){
			res = x.second;
			g= x.first;
		}
		else if(x.second == res){
			if((int)x.first < (int) g)
				g = x.first;
		}
	}
	cout<<g<<" "<<res<<endl;

	return 0;
}
