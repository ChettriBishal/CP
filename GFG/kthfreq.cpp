#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	unordered_map<int,int>g;
	for(int i=0;i<n;i++){
		cin>>a[i];
		g[a[i]]++;
	}
	vector<int>fin; // fin to store those elements whose count >k
	for(auto i: g)
		if(i.second>k)
			fin.push_back(i.first);
	if(fin.size()!=0){
		sort(fin.begin(),fin.end());
		for(auto i: fin)
			cout<<i<<" ";
	}
	else
		cout<<-1;
	cout<<endl;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
