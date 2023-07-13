/*
 * Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the
 * maximum value of x, such that, n! % kx = 0
 *
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n,k;
    cin>>n>>k;
    int res=INT_MAX,occ=0;
    // finding the factorisation of k
    for(int i=2;i*i<=k;i++)
    {
        // occ is the number of times i occurs in prime factorisation of k
        if(k%i==0){
            occ=0;
            while(k%i==0){
                occ++;
                k/=i;
            }
            // then find out the occurences of i in n!
            int cnt=0;
            int p=i; // p-->powers of i
            while(p<=n){
                cnt+=n/p;
                p*=i;
            }
            res=min(res,cnt/occ);
        }
    }
    // if any prime factor is remaining
    if(k>1){
        int cnt=0;
        int p=k;
        while(p<=n){
            cnt+=n/p;
            p*=k;
        }
        res=min(res,cnt); // cnt/occ but occ=1 for a prime number 
    }
    if(res==INT_MAX)
        cout<<0<<"\n";
    else
        cout<<res<<"\n";

}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    
    return 0;
}
