/* Finding factors of sieve prime based */
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
vector<pair<int,int>> factorize(int no, vector<int>&primes)
{
    vector<pair<int,int>> res;
    for(int i=0;primes[i]*primes[i]<=no;i++)
    {
        if(no% primes[i]==0){
            int cnt=0;
            while(no % primes[i]==0){
                cnt++;
                no/=primes[i];
            }
            res.push_back({primes[i],cnt});
        }
    }
    // if there is a prime number still remaining 
    if(no!=1){
        res.push_back({no,1});
    }
    return res;

}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    int N=1000000;
    int p[N]={};
    vector<int>primes= sieve(p,N);

    int t;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;
        cout<<"Prime factors of "<<no<<"\n";
        vector<pair<int,int>> factors =factorize(no,primes);
        for(auto k:factors)
            cout<<k.first<<" ^ "<<k.second<<"\n";
        cout<<"\n";
    }

    return 0;

}
