#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,l;
    cin>>n>>l;
    vector<ll>a(n);
    for(auto &x:a) cin>>x;
    sort(a.begin(),a.end());
    double res=max(a[0],l-a[n-1]);
    ll k=LLONG_MIN;
    for(int i=1;i<n;i++)
        k=max((a[i]-a[i-1]),k);
    res=max((float)k/2.0,res); // dividing by 2 cause there are two adjacent lanterns 
    cout<<fixed<<setprecision(9)<<res<<"\n";
    return 0;


}

/*
 * every lantern other than the first and last one contributes to half of the k 
 * a[i]....................|................... a[i+1]
 *    |    <-- k/2 -->     | <--  k/2  -->     |
 *    Thus the distance between two lanterns is k overall
 *  Remember we want radius to be minimum possible while also making sure that all points are lit
 */
