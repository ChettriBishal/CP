#include<bits/stdc++.h>
using namespace std;
#define n 1000000
#define int long long
vector<bool>isprime(n,true);
vector<int>sump(n);
void sieve()
{
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                isprime[j]=false;
        }
    }
    sump[0]=sump[1]=0;
    sump[2]=2;
    int sum=2;
    for(int i=3;i<=n;i++)
    {
        if(isprime[i]){
            sum+=i;
            sump[i]=sum;
        }
        else
            sump[i]=sum;
    }
}
signed main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int up;
        cin>>up;
        cout<<sump[up]<<endl;
    }
    return 0;
}
