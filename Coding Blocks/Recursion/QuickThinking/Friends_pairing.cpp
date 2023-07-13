/*
 *Given N friends who want to go to a party on bikes.
 *Each guy can can go as a couple or single.
 *
 *Find the number of ways in which N friends (with N bikes) can go to the party
 */

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll nCr(ll n, ll r)
{
    if(n-r<r)
        r=n-r;
    ll num=1, den=1;

    if(r!=0){
        while(r){
            num*=n;
            den*=r;

            ll m= __gcd(num,den);
            num/=m;
            den/=m;

            n--;
            r--;
        }
    }
    
    return num;
}

ll f(ll n)
{
    if(n==0 or n==1)
        return 1;

    return f(n-1) + (n-1)* f(n-2); // nCr(n-1,1) = n-1
}

int main()
{
    cout<<"Enter the number of people\n";
    ll n;
    cin>>n;
    cout<<f(n)<<endl;

    return 0;
}
