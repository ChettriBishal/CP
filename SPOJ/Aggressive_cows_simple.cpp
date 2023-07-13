// Aggressive Cows SPOJ 
// Binary Search in monotonic search space 

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;


bool canplace(ll* stalls, int n, int cows, ll min_sep)
{
    ll prev_cow = stalls[0];
    // place the first cow in the first stall

    int cnt=1; // count taking care of number of cows placed

    for(int i=1;i<n;i++)
    {
        if(stalls[i]-prev_cow>=min_sep){
            prev_cow = stalls[i];
            ++cnt;

            if(cnt==cows){
                return true;
            }
        }
    }

    return false;
}



void solve()
{
    int n,cows;
    cin>>n>>cows;
    ll stalls[n];
    
    for(int i=0;i<n;i++)
        cin>>stalls[i];
    
    sort(stalls,stalls+n);

    ll s=0;
    ll e=stalls[n-1]-stalls[0];
   
    ll res=0; // initially assuming the separation to be minimum possible

    while(s<=e){
        ll mid=(s+e)/2;
        
        if(canplace(stalls,n, cows,mid)){
            res = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
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
