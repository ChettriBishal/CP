#include<bits/stdc++.h>
using namespace std;

// to find the least prime factor from 1 to n
// Modified sieve
vector<int> leastprimefactor(int n)
{
    vector<int> least_prime(n+1,0);
    least_prime[1] = 1;
    for(int i= 2;i<=n;i++){
        if(least_prime[i] == 0){
            least_prime[i] = i;
            for(long j = i*i;j<=n;j+=i){
                if(least_prime[j] == 0){
                    least_prime[j] = i;
                }
            }
        }
    }
    return least_prime;
}

int main()
{
    int n;
    cin>>n;

    vector<int> bis = leastprimefactor(n);

    for(auto k:bis)
        cout<<k<<" ";
    cout<<endl;

    return 0;
}
