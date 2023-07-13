#include<bits/stdc++.h>
using namespace std;
void update(int*a,int n,int *up,int k)
{
	for(int i=0;i<k;i++)
	{
		int j;
		cin>>j;
		a[j-1]+=1;
		for(int r=0;r<n;r++)
			cout<<a[r]<<" ";
		cout<<endl;
	}
	up[0]=a[0];
	for(int i=1;i<n;i++)
		up[i]=up[i-1]+a[i];
	for(int i=0;i<n;i++)
		cout<<up[i]<<" ";
	cout<<endl;
}
int main()
{
	int n,k;
	cin>>n;
	int a[n]={0},up[n]={0};
	cin>>k;
	update(a,n,up,k);
	return 0;
}
