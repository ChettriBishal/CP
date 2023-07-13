#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+1;
#define pb push_back
vector<bool> isprime(MAXN+1,true); // giving MAXN + 1 is important (+1)
//vector<bool> sieve() //prime sieve
void sieve()
{
	isprime[0]=isprime[1]=false;
	for(int i=2;i*i<=MAXN;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=MAXN;j+=i)
				isprime[j]=false;
		}
	}
	//return isprime;
}
bool issqr(ll n) // to check if a number is a square
{
    ll k=sqrt(n);
    if(k*k==n)
        return true;
    else
        return false;
}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    ll n;
    cin>>n;
    ll val;
    //vector<bool> primes=sieve();
    sieve();
    for(ll i=0;i<n;i++){
        cin>>val;
        if(issqr(val) && isprime[sqrt(val)])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    return 0;
}
/*
 * Check if a number can be represented as square 
 * If yes then check if the square root of the number is prime
 *  If yes then its T prime
 * https://codeforces.com/problemset/problem/230/B
*/
