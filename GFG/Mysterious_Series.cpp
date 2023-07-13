/*
 * Find the Nth term of the Mysterious series.
 * N    Nth term
 * 1    5
 * 2    10
 * 3    26
 * 4    50
 * 5    122
 * .
 * .
 * .
 * 10    842
 */
#include<bits/stdc++.h>
using namespace std;

long long nthmysterious(long long n)
{
    int NN = 1e4 +1;
    vector<int> primes(NN+1,1);
    vector<int> res(NN);
    primes[0] = primes[1] = 0;

    for(int i=4;i<=NN;i+=2) 
        primes[i] = 0;   
    for(int i= 3;i *i<=NN;i++){
        if(primes[i]){
            for(long j = i*i;j<=NN;j+=i)
                primes[j] = 0;
        }
    }
    int k = 1;
    for(int i = 1;i<=NN;i++){
        if( primes[i] ){
            res[k++] = i*i +1;
        }
    }

    return res[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<nthmysterious(n)<<endl;

    return 0;
}
