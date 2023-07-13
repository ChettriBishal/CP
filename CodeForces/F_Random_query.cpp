#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(MAX+1);
    vector<ll>ans(MAX,0),lastocc(MAX,0);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=ans[i-1]+(i-lastocc[a[i]]);
        lastocc[a[i]]=i; // updating the last occurence of a[i]
        sum+=ans[i];
    }
    double res=(double)(2*sum-n)/(n*n);
    cout<<fixed<<setprecision(6);
    cout<<res<<"\n";
    return 0;

}
/*
 * ans stores the number of unique elements till index i
 * lastocc stores the most recent index of element (ie the last occurence )
 * sum is simply storing the sum of the unique elements over every interval
 * and finally we're subtracting n from the answer as every single block is included extra
*/
