/*
 * Bishal
 * 13-May-21 2:50:41 AM
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>subsets(vector<ll>a) // to get subsets of the vector
{
    int n=a.size();
    vector<ll>sub;
    for(ll i=0;i<(1<<n);i++)
    {
        ll sum=0;
        for(ll j=0;j<n;j++)
            if(i & (1<<j))
                sum+=a[j];
        sub.push_back(sum);
    }
    return sub;
}
int main()
{
    int size,n,m;
    cin>>size;
    n=size/2;
    m=size-n;
    ll A,B;
    cin>>A>>B; // constraints
    vector<ll>a(n),b(m); // partition the array into two 
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    vector<ll>sa,sb; // to store the sum of subsets
    tie(sa,sb)= make_tuple(subsets(a),subsets(b));
    sort(sb.begin(),sb.end()); // will be performing binary search in second array
    ll cnt=0;
    
    for(auto val:sa){   
        auto start=lower_bound(sb.begin(),sb.end(),A-val)-sb.begin();
        auto end=upper_bound(sb.begin(),sb.end(),B-val)-sb.begin();
        cnt+=(end-start); // getting the range of values under constraint
    }
    cout<<cnt<<"\n";
    return 0;
}
/*
 * https://www.spoj.com/problems/SUBSUMS/
 * */
