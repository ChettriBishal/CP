#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	set<char>d,e; // d to store the diagonal elements//e for other elements
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			char ch;
			cin>>ch;
			if(i==j || i+j+1==n) d.insert(ch);
			else e.insert(ch);
		}
	// if there's only one kind for both the diagonals 
	// and if there's only one kind for other elements 
	if(d.size()==1 && e.size()==1 && *(d.begin())!=*(e.begin()))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}