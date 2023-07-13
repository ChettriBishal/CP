#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>a(n),pre(n+3,0);
        ll sum=0ll;
        pre[0]=1; // initially there is only one hole having sum % n =0
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            sum%=n;
            sum=(sum+n)%n; // this will lie in the range [0,n]
            pre[sum]++;
        }
        ll res=0;
        for(auto g:pre){
            if(g>=2) // nC2 here n=g
                res+=g*(g-1)/2;
        }
        cout<<res<<"\n";
    }
    return 0;

}
/*
 *   a_0 a_1 a_2 a_3 a_4
 *   1    3   2   6   4   --> array elements
 *0  1    4   6   12  16   --> prefix sum array
 *0  1    4   1   2   1    --> prefix sum array % N

 * We need to find segments such that 
 * (pre[j]-pre[i])%N=0
 * pre[j] % N = pre[i] % N 
*/
