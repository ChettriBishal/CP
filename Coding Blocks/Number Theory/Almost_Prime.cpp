#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sieve(int n) // this sieve will store the number of prime divisors a number has
{
    int facnt[n+1]={}; // to store the factor count of a prime number for n
    // in facnt primes are marked by 0
    for(int i=2;i<=n;i++)
    {
        if(!facnt[i]) // if i is prime
        {
            for(int j=i;j<=n;j+=i)
                facnt[j]++; // incrementing the count for every j ( i is prime factor)
        }
    }
    int res=0;
    for(int i=2;i<=n;i++)
        if(facnt[i]==2) res++;
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    sieve(n);
    
    return 0;

}
/* For visualisation consider n=10 take pen and paper */
