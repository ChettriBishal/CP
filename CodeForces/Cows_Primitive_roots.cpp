/*
17-Apr-21 10:10:07 AM
Bis
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int modpow(int a, int b,int m) // binary exp
{
    int res=1;
    while(b>0)
    {
        if(b&1) 
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1; 
    }
    return res;
}
signed main()
{
    int p;
    cin>>p;
    int cnt=0;
    if(p==2) cnt++;// cause we're 2 satisfies the criteria but we start iteration from x=2
    for(int x=2;x<p;x++)
    {
        bool check=true;
        for(int ex=1;ex<=p-2;ex++) // ex=exponent /power
            if(modpow(x,ex,p)==1){ // all powers less than p-1 must not be divisible by p
                check=false;
                break;
            }
        if(modpow(x,p-1,p)!=1)// x^(p-1)-1 must be divisible by p
            check=false;
        if(check) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
