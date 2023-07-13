#include"bits/stdc++.h"
using namespace std;
const int MAXN=1000000;
void sieve(int *p)
{
    // firstly mark all odd numbers as primes 
    // as we will have all primes except 2 as odd
    for(int i=3;i<=MAXN;i+=2)
        p[i]=1;
    p[1]=p[0]=0; 
    p[2]=1; // 2 is the only even prime
 
    // sieve
    for(long long i=3;i*i<=MAXN;i+=2)
    {
        if(p[i]==1) // marking all multiples of p[i] as not prime
        {
            for(long long j=i*i;j<=MAXN;j+=i)
                p[j]=0;
        }
    }
}

int main()
{
    int primes[MAXN]={0};
    cout<<"Enter value for n:\n";
    int n;
    cin>>n;
    sieve(primes);
    for(int i=0;i<=n;i++)
        if(primes[i]==1)
            cout<<i<<" ";

    return 0;

}
