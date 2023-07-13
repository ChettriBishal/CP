#include<bits/stdc++.h>
using namespace std;
#define int long long
#define size 63000009
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int>bis(n);
	for(int &x:bis)
		cin>>x;
	sort(bis.begin(),bis.end(),greater<int>());
	queue<int>a,b;
	for(int x:bis)
		a.push(x);
	int res[size];
	for(int i=1;i<size-8;i++)
	{
		if(b.empty())
		{
			if(a.empty())
				break;
			int val=a.front();
			res[i]=val;
			a.pop();
			b.push(val/2);
		}
		else if(a.empty())
		{
			int val=b.front();
			res[i]=val;
			b.pop();
			b.push(val/2);
		}
		else{
			int val1=a.front();
			int val2=b.front();
			if(val1>val2){
				res[i]=val1;
				a.pop();
				b.push(val1/2); // val/2 is smaller and pushed at the end #queue
			}
			else{
				res[i]=val2;
				b.pop();
				b.push(val2/2);
			}
		}
	}
	while(m--)
	{
		int x;
		cin>>x;
		cout<<res[x]<<endl;
	}
	return 0;
}
/*
val/2 is smaller so in a sorted scenario smaller values are at back
hence val/2 is 'pushed' in queue FIFO so last pushed values stay at the end
---->which means its sorted in decreasing order
and queue_name.front() would always give the largest element in the list
*/



