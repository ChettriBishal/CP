#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll c;
    cin>>c;
    int n=(int)log2(c)+1;// n is the number of bits in c
    ll xoro=(1<<n)-1;
    ll a=xoro^c;
    ll t=(1<<(n-1));
    a|=t; // switching on the first bit
    ll b=a^c;
    cout<<a*b<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
 * So the approach is to first find the value of A from C (which is given)
 * Like consider 13-->1101 we'll need A which has all bits apart from the first one toggled
 * 1 1 0 1--->13
 * 1 0 1 0--->10
 *
 * Inorder to get 10 we need to xor 13 with 1111 (2^4 -1) (here xoro=2^4-1=1111)
 * so 1101 ^ 1111 ---> 0010 
 * We OR the number obtained with 2^3
 * 0010 | 1000 --->1010 (A)
 * Then from A we easily get the value of B 
 * 1010 ^ 1101 --->0111
 *   A      C        B
 */
