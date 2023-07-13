#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
const ll N = 10000000;
int32_t main()
{

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    bitset<N> primes;
    primes.set();

    primes[1] = primes[0] = 0;

    vector<ll> prime_numbers;
    for(ll i = 4;i<N;i+=2)
        primes[i] = 0;
    prime_numbers.push_back(2);
    for(ll i= 3;i <N;i+=2){
        if(primes[i]){
            prime_numbers.push_back(i);
            for(ll j = (ll)i*i;j<N;j+=i){
                primes[j] = 0;
            }
        }
    }
    int t= 1;
    //cin>>t;
    while(t--){
        int num;
        cin>>num;
        cout<<prime_numbers[num-1]<<endl;
    }

    return 0;


}
