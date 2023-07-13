#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
using namespace std;
typedef long long ll;
#define setbits  __builtin_popcountll
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
    vector<int> arr,time;
    int n,k;
    cin>>n>>k;
    arr.resize(n), time.resize(n,0);
    for(int & x: arr) cin>>x;

    int left = -1,right = -1;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            left = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i] > 0){
            right = i;
            break;
        }
    }
    if(left == -1){
        cout<<0<<endl;
        return;
    }
    int cur = 1; // cause we're starting from one next to the position
    for(int i=(left + 1)%n;i != left;i = (i+1)%n){
        if(arr[i] > 0)
            cur = 0;
        time[i] = cur;
        cur++;
    }
    cur = 1; // now moving backwards
    for(int i=(right-1 +n)%n;i != right;i = (i-1+n)%n){
        if(arr[i] > 0)
            cur = 0;
        time[i] = min(time[i],cur);
        cur++;
    }

    ll res = accumulate(arr.begin(),arr.end(),0);
    for(int i=0;i<n;i++){
        res += 2 * max(k- time[i],0);
    }

    cout<<res<<endl;

}
signed main()
{
	#ifdef Bis
        freopen("input.txt","r",stdin);
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    io;
    int t;
    cin>>t;
    while(t--)
        solve();
	#ifdef Bis
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr <<endl<< "Time Elapsed: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
    return 0;
}

