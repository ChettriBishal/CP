#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	int k=2,ind=0;
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n/2;i++) // even numbers
	{
		a[i]=k;
		k+=2;
		ind=i;
	}
	k=1;
	bool check=true;
	for(int i=ind+1;i<n;i++) //odd numbers
	{
		a[i]=k;
		k+=2;
		if(abs(a[ind+1]-a[ind])==1){
			check=false;
			break;
		}
	}
	if(check){
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
	}
	else
		cout<<"NO SOLUTION\n";
	return 0;

}