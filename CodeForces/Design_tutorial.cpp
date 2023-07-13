#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime( ll num )
{
    for(ll i=2;i*i<=num;i++){
        if(num %i ==0){
            return false;
        }
    }
    return true;
}

void express(ll a,ll b,ll n)
{
    if(a < 4 || b< 4) // smallest composite number = 4
        return;

    if(!isprime(a) && !isprime(b)){
        cout<<a<<" "<<b<<endl;
        return;
    }

    express(a+1,b-1,n);

}

int main()
{
    ll n;
    cin>>n;
    express(4,n-4,n);

    return 0;
}
// https://codeforces.com/contest/472/problem/A
