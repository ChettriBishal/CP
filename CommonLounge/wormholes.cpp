#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,x,y;
	cin>>n>>x>>y;
	vector<int>v(x),w(y);
	vector<pair<int,int>>a; // to store the contest start and end times
	for(int i=0;i<n;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		a.pb({a1,a2});
	}
	for(int &i:v)
		cin>>i;
	for(int &i:w)
		cin>>i;
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	int time=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int t=lower_bound(v.begin(),v.end(),a[i].f)-v.begin(); // time of wormhole which is nearest to and equal to (or greater) than the contest start time
		if(v[t]!=a[i].f)
			--t; // one step lower cause lower_bound give value to nearest to and greater (if not equal), wormhole time should be before or equal to start time
		if((t+v.begin()==v.end()) || t<0)
			continue;
		int start=v[t];
		t=lower_bound(w.begin(),w.end(),a[i].s)-w.begin();
		if(t+w.begin()==w.end())
			continue;
		int end=w[t];
		//cout<<start<<" "<<end<<endl;
		int val=end-start+1;
		time=val<time?val:time;
	}
	cout<<time<<endl;
}
