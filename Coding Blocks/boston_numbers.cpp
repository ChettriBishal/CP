#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sumof_dig(ll );
ll sumof_factors(ll n) // generating sum of digits of prime factors of n 
{
    ll res=0ll;
    while(n%2==0){
        n/=2;
        res+=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            res+=sumof_dig(i);
            n/=i;
        }
    }
    if(n>2) 
        res+=sumof_dig(n);
    return res;
}
ll sumof_dig(ll n){
    ll res=0ll;
    while(n){
        res+=(n%10);
        n/=10;
    }
    return res;
}
int main()
{
    ll n;
    cin>>n;
    int sumofdig=0;
    ll temp=n;
    while(temp){
        int k=temp%10;
        sumofdig+=k;
        temp/=10;
    }
    ll check=sumof_factors(n);
    if(check==sumofdig)
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
    
    return 0;
    

}
