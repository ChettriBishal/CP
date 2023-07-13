#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<int>st;
	multiset<int>mt;
	vector<int>a(n);
	for(int &x:a){
		cin>>x;
		st.insert(x);
		mt.insert(x);
	}
	if(n==1){
		cout<<"YES\n";
	}
	else{
		bool en=true;
		int half=n/2+(n%2);
		for(auto i=st.begin();i!=st.end();i++)
		{
			//cout<<*i<<" "<<mt.count(*i)<<endl;
			if(mt.count(*i)>half){
				en=false;
				break;
			}
		}
		if(en)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
