/*
 * Given two integers L and R,
 * write a program that finds the count of numbers having prime number of set bits 
 * in their binary representation in the range [L, R].
 * Input: L = 6, R = 10
 * Output: 4
 * Explanation: 6, 7, 9, 10 having
 * prime set bits between 6 and 10.
 *
 */
#include<bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if(x == 0 || x == 1) return false;

    for(int i = 2;i*i<=x;i++ ){
        if(x % i == 0)
            return false;
    }
    return true;
}

int primesetBits(int l,int r)
{
    vector<int> prime(11,0); // cause the maximum no of set bits is below 11 for numbers till 1000
    for(int i= 0;i<=10;i++ ){
        prime[i] = isprime(i);
    }

    int cnt = 0;
    for(int i=l;i<=r;i++ ){
        int setbits = __builtin_popcount(i);
        if(prime[setbits]) cnt++;
    }

    return cnt;
}


int main()
{
    cout<<log2(1000)<<endl;
    int l,r;
    cin>>l>>r;
    cout<<primesetBits(l,r)<<endl;

    return 0;

}
