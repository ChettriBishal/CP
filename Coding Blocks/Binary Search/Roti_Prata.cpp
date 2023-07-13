/*
 *Using binary search 
 *25-Jul-21 8:59:52 PM
 *
 */

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long ll;

bool correct(int* ranks,int n, int p, ll time)
{
   int rotis = 0;
   for(int i=0;i<n;i++)
   {
       int j=1;
       int t = 0;
       while(((j*ranks[i])+ t)<=time){
            ++rotis;
            t+=(j*ranks[i]);
            j++;
       }
   }
   if(rotis>=p)
       return true;
   else
        return false;
}

void solve()
{
    int p;
    cin>>p;

    int l;
    cin>>l;
    int ranks[l];
    for(int&x:ranks) cin>>x;
    
    sort(ranks,ranks+l);

    ll s = 0ll;
    ll e = ranks[0]* (p*(p+1))/2; // time taken by the fastest chef to complete  

    ll res = LLONG_MAX; 
    while(s<=e){
        ll mid = (s+e) /2;

        if(correct(ranks,l,p,mid)){
            res = min(res,mid);
            e = mid-1;
        }
        else
            s = mid+1;
    }

    cout<<res<<endl;

}


int main()
{
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
