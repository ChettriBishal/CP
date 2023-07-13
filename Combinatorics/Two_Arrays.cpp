#include<iostream>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll power(int a, int b)
{
    ll res =1;
    while(b){
        if( b&1 ){
            res = (res *1LL* a) % MOD; // multiplying by 1LL very important to ensure the product doesn't overflow
        }
        a = (a *1LL* a) % MOD;
        b >>= 1;
    }

    return res;
}

ll factorial(int n )
{
    ll res = 1;
    for(int i=1;i<=n;i++){
        res = (res * i) % MOD;
    }

    return res;
}

ll nCr(int n,int r)
{
    ll res = factorial(n); 
    ll den = (factorial(n-r) * factorial(r)) % MOD; // denominator term
    res = (res * power(den,MOD-2)) % MOD;

    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int N = 2*m; // number of places 
    int K = n; // available options

    cout<<nCr(N + K -1 ,K -1)<<endl;

    return 0;
}
