#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nCr(ll n,ll r)
{
    // nCr= nCn-r
   if(n-r<r)
       r=n-r;
    ll num=1,den=1;
    if(r!=0){
        // only run the loop till r reaches 0 
        // r controls the part (n-r)! which is actually cancelled by the numerator
        // when r turns zero it's the end of the part until the cancellation of factorial part of the numerator
        // so we're cancelling numerator by not calculating that part which is cancelled 
        while(r) 
        {
            num*=n;
            den*=r;
            
            ll m= __gcd(num,den);
            num/=m;
            den/=m;

            n--;
            r--;
        }  
    }
    else
        num=1;

    return num;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        ll res=nCr(n-1,r-1);
        cout<<res<<"\n";
    }
    return 0;
    
}
/*
 * consider 8C3
 *    8! 
 *  --------
 *  3! (8-3)!
 *
 *  
 *  1   2   3
 *  _________
 *  8 X 7 X 6 X 5!
 * -----------------
 *  3 X 2 X 1 X 5 !
 *
 * 5! is cancelled and hence is not calculated
 * See the number of iterations we make for numerator is until r reaches 0
 *  
*/
