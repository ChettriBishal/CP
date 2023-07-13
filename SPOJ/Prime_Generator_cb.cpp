#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5; // store primes upto root(n)  
vector<int>primes; 

bitset<N+3> b; // to mark if prime or not

void sieve() // creating primes upto N
{
    b.set();
    for(int i=4;i<=N;i+=2)
        b[i]=0;
    b[0]=b[1]=0;
    // we are not looping till root of N as it is already estimated root of n
    for(int i=2;i<=N;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*2;j<=N;j+=i)
                b[j]=0;
        }
    }
}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m; 
        cin>>m>>n; // ....[m,n]

        bool segment[n-m+1]; // segment sieve

        for(int i=0;i<n-m+1;i++) // initially setting all as true
            segment[i]=true;
        
        for(auto x:primes){
            
            if(x*x>n) // iterate over values less than square root of square root of n
                break;

            int start=(m/x)*x; // first nearest multiple of x
            
            // if x>m then start=0 which is incorrect
            // if x=m then x itself will be marked as "not prime" which is incorrect
            if(x>=m && x<=n) 
                start=2*x;
            // marking all muliples of x in range start to n as not prime
            for(int i=start;i<=n;i+=x){
                segment[i-m]=false;
            }
        }
        for(int i=m;i<=n;i++){
            if(segment[i-m] && i!=1)
                cout<<i<<"\n";
        }

        cout<<"\n";
    }

    return 0;
}
