// space optimised sieve using bitset
// Checking if a number is prime or not ~ 10^14
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
const ll N = 1e7;

bitset<N+3>b;
vector<ll> primes;

void sieve()
{
    // set all bits 
    b.set();
    
    b[0]=b[1]=0; // not prime
    for(ll i=4;i<=N;i=i+2) // marking all even numbers except 2 as not prime
        b[i]=0;

    primes.push_back(2); // only even prime
    for(ll i=3;i*i<=N;i+=2)
    {
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=N;j+=i)
                b[j]=0;
        }
    }  
    
}
int main()
{
    sieve();
    // printing the first 100 primes
    for(ll i=0;i<100;i++)
        cout<<primes[i]<<" ";
    return 0;

}

//bool primes[100] would take 800 bits ....as 1 byte = 8 bits
// however with bitset it would take only 100 bits
