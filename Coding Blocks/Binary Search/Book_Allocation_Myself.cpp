#include<iostream>
#include<climits>
#include<numeric>
#include<algorithm>
using namespace std;
typedef long long ll;
bool allocated(ll* a,ll n,ll m,ll min_pages)
{
    ll stud_cnt = 1;
    ll pages = 0;

    for(ll i=0;i<n;i++){
        if(a[i]+pages > min_pages){
            stud_cnt++;
            pages = a[i];

            if(stud_cnt > m) return false;
        }
        else{
            pages += a[i];
        }
    }

    return true;
}

int main()
{
    ll n,m;
    cin>>n>>m;

    ll a[n];

    for(ll &x: a) cin>>x;

    sort(a,a+n); 

    ll s = a[n-1];

    ll e = accumulate(a,a+n,0);

    ll res = INT_MAX;

    while(s<=e)
    {
        ll mid = (s+e)/2;

        if(allocated(a,n,m,mid)){
            res = min(res,mid);
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    cout<<res<<endl;

    return 0;
}
