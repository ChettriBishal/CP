#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define mod 1e9+7
int mpow(int a,int b,int m)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
int gcd(int a,int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
int ext_gcd(int a,int b,int&x,int&y) // extended euclid algorithm
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int d=ext_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}
int mod_inv(int a,int m,int&x,int&y) // to find the modulo inverse
{
	ext_gcd(a,m,x,y);
	return (x%m+m)%m;
}
signed main()
{
	int a,b,c,m,x,y;
	cin>>a>>b>>c>>m;
	int c_inv=mod_inv(c,m,x,y); // c inverse
	cout<<((mpow(a,b,m)%m)*(c_inv%m))%m<<endl;
	return 0;
}
