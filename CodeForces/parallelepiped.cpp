#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>a(3);
	for(int &x:a)
		cin>>x;
	int lb,bh,hl,b,h,l;
	for(int i=1;i<=3;i++)
	{
		lb=a[i%3];
		bh=a[(i+1)%3];
		hl=a[(i+2)%3];
		int h2=(bh*hl)/lb;
		if(sqrt(h2)*sqrt(h2)==h2)
		{
			h=sqrt(h2);
			l=hl/h;
			b=bh/h;
			break;
		}
	}
	cout<<4*(l+h+b)<<endl;
	return 0;
}
/*
auth: bishal
let the edges be l,b,h
so we are given 
l*b....(i)
b*h....(ii)
l*h....(iii)
dividing (i) by (ii)
we get:
l*b/b*h=l/h
ie..
lb/bh*h=l....(iv)
using (iv) in (iii)
h^2=(h*l)*(b*h)/(l*b)
if it satisfies as integer then we found the value
*/