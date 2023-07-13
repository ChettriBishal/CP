#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
typedef long long ll;
void sieve(int * p)
{
    p[0]=p[1]=0;
    p[2]=1;
    for(ll i=3;i<=N;i+=2)
        p[i]=1;
    for(ll i=2;i*i<=N;i++)
    {
        if(p[i]){
            for(ll j=i*i;j<=N;j+=i)
                p[j]=0;
        }
    }
}
int main()
{
    int primes[N]={0};
    sieve(primes);
    int pre[N+3]={0}; // to store the cumulative sum
    pre[2]=1;
    for(int i=3;i<=N;i++)
        pre[i]=pre[i-1]+primes[i];
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<"\n";
    }
    return 0;

}
