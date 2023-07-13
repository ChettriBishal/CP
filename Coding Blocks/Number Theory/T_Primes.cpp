/* Squares of primes are T primes 
Consider 4 having divisors =1, 2, 4 
25 = 1, 5, 25
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool checkprime(ll n) // to check if a number is prime
{
    if(n<4)
        return n==2 || n==3;
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0) 
            return false;
    }
    return true;

}

bool solve()
{
    ll x;
    cin>>x;
    ll root=sqrt(x);
    if(root*root==x){
        if(checkprime(root))
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve()?cout<<"YES\n":cout<<"NO\n";

    return 0;
}
