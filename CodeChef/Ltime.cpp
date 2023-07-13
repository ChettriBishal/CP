#include<iostream> // stack based implementation
#include<vector>
#include<stack>
#define endl '\n'
using namespace std;
#define int long long
void update(vector<int>&h,vector<int>&up,int k) // up--->jr or jl
{
	int n=h.size();
	stack<int>s;
	switch(k)
	{
		case 1: // left 
		for(int i=0;i<n;i++)
		{
			while(!s.empty())
			{
				int pos=s.top();
				if(h[pos]>=h[i]) break;
				else s.pop();
			}
			if(!s.empty()) up[i]=s.top();
			else up[i]=-1;
			s.push(i);
		}
		break;
		case 2:   // right 
		for(int i=n-1;i>=0;i--)
		{
			while(!s.empty())
			{
				int pos=s.top();
				if(h[pos]>=h[i]) break;
				else s.pop();
			}
			if(!s.empty()) up[i]=s.top();
			else up[i]=-1;
			s.push(i);
		}
	}
}
void solve()
{
	int n;
	cin>>n;
	vector<int>heights(n);
	vector<int>jl(n),jr(n); // jump right and jump left
	for(int &x:heights)
		cin>>x;
	update(heights,jl,1);
	update(heights,jr,2);
	/*
	for(int s:jl)
		cout<<s<<" ";
	cout<<endl;
	for(int s:jr)
		cout<<s<<" ";
	cout<<endl; */
	vector<int>right(n),left(n);
	for(int i=0;i<n;i++) // left one
	{
		if(jl[i]==-1 or heights[jl[i]]!=heights[i]) continue;
		else left[i]=1+left[jl[i]];
	}
	for(int i=n-1;i>=0;i--) // right one
	{
		if(jr[i]==-1 or heights[jr[i]]!=heights[i]) continue;
		else right[i]=1+right[jr[i]];
	}
	/*
	for(int x:left)
		cout<<x<<" ";
	cout<<endl;
	for(int x:right)
		cout<<x<<" ";
	cout<<endl; */
	for(int i=0;i<n;i++)
		cout<<left[i]+right[i]<<" ";
	cout<<endl;
}
int32_t main()
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
/*
jl signifies that largest index with respect to i such that h_j>=h_i 
ie the index of the student after which that student standing at i can't see other students
/for each i, the closest student to the left and the right of i who has height ≥ h_i /
jr signifies that largest index with respect to j such that h_i>=h_j
vice versa

*/
