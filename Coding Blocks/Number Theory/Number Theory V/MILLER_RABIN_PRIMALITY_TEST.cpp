// Miller Rabin Primality test ---> 3 * 10 ^ 18
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll modmul(ll a, ll b, ll mod) // modular multiplication 
{
    ll res = 0;
    while(b ){
        if( b & 1ll )
            res += a;
        res %= mod;
        a %= mod;
        a *= 2ll;
        b >>= 1ll;
    }
    return res;
}


ll modular_exponentiation(ll a, ll b , ll mod)
{
    ll res= 1ll;
    while(b){
        if( b& 1ll )
            res = modmul(res,a, mod);
        a = modmul(a,a,mod);
        b >>= 1ll;
    }

    return res;
}

bool miller_rabin(ll n){
    if( n < 4 ) // only prime numbers less than 4 
        return n == 2 || n == 3;

    if(n % 2 == 0)  // if even 
        return false;

    // now n is odd, means n - 1 is even 
    ll d = n-1 , s = 0;

    while(d % 2 == 0){
        s++;
        d /= 2;
    }

    // d is now odd --> n - 1 = d * (2 ^ s)
    
    // now take random numbers from [2, n-2] ...technically we take top 9 prime numbers
    vector<ll> a{2,3,5,7,11,13,17,19,23}; 
    for(int i=0;i < a.size();i++){
        
        if(a[i] > n-2 ) break;

        ll ad = modular_exponentiation(a[i],d,n); // (a ^ d) % n

        if( ad == 1 ) continue;

        bool prime = false;
        for(int r=0;r <= s - 1; r++){ // r -- > [0, s-1]
           ll rr = modular_exponentiation(2,r,n);  // (2 ^ r ) %n

           ll ard = modular_exponentiation(ad, rr, n) ; // (a ^ (d * (2 ^ r))) % n
           if(ard == n-1){
               prime = true;
               break;
           }
        }
        if(prime == false){
            return false;
        }
    }
    return true;

}

void tests(){
    ll n;
    cin>>n;
    if(miller_rabin(n)){
        cout<<"Prime\n";
    }
    else
        cout<<"Not Prime\n";

}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t = 30;
    //cin>>t;
    while(t--)
        tests();


    return 0;
}
