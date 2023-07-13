/* Finding no of divisors of a number sieve based */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> sieve(int *p,int n) // optimised sieve
{
    p[0]=p[1]=0;
    p[2]=1;
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
        p[i]=1;
    for(int i=3;i*i<=n;i+=2)
    {
        if(p[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=n;j+=i)
                p[j]=0;
        }
    }
    return primes;
}
int noofdivisors(vector<int>&primes,int num)
{
    int cnt=1;
    for(int i=0;primes[i]*primes[i]<=num;i++)
    {
        if(num% primes[i]==0){
            int p=0;   // here p is actually the the maximum power of the prime factor ( aka count )
            while(num % primes[i]==0){
                num=num/primes[i];
                p++;
            }
            cnt=cnt*(p+1);
        }
    }
    // if there is a prime number remaining then it will also contribute to divisors 
    // we're left with a prime number whose power is 1 .... [0,1]= 2 powers, so we multiply by 2
    if(num!=1){
        cnt=cnt*2;
    }
    return cnt;
}
/* The powers in which a prime factor can occur if the exponent is p
....0  1  2  3   4   ..... p ----> p+1 
*/
int main()
{
    int N=1000000;
    int p[N]={};
    vector<int>primes= sieve(p,N);

    cout<<"Enter a number to find the number of divisors\n";
    int num;
    cin>>num;
    cout<<noofdivisors(primes,num)<<endl;
    return 0;

}

