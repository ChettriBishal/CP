#include<iostream>
#include<vector>
//#include"bistimulus.h"
using namespace std;
// given n can be maximum of 10 ^ 9 so we take N about the root of "n" in worst case
const int N = 100001;


vector<int> p(N, true);
vector<int> primes;

void sieve()
{
    p[1] = false;


    // here we aren't looping upto square root of N because: 
    // N = sqrt(n) // where n is supplied from the user 
    // "n" in worst case can be 10^9 

    for(int i= 2; i < N;i++){
        if(p[i]){
            primes.push_back(i);
            for(long j = i * 2;j< N ; j+=i)
                p[j] = false;
        } 
    }

}


int main()
{

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    sieve();
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<bool> segment(n-m + 1,true);
        for(auto &x: primes){
            if(x * x > n) 
                break;

            int start = (m / x ) * x;

            if(x >= m && x <= n){ // if the prime number is within the range of segment sieve 
                start = 2* x;
            }

            //debug(start);
            
            for(int i = start ; i <= n;i+= x){
                if(i >= m) // like m = 99 and we start with 98 which is less than m  so we skip that 
                    segment[i - m] = false; // not prime
            }

        }
        for(int i= m;i<=n;i++){
            if(segment[i - m] && i != 1)
                cout<<i<<endl;
        }
        cout<<endl;
    }
    
    return 0;

}

