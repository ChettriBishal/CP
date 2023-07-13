// ॐ मणि पद्मे हूँ
#include<bits/stdc++.h>
#ifdef Bis 
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define setbits  __builtin_popcountll
#define ll long long 
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PI 3.141592653589793238
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ALL_THE(Cake,Lie) for(auto Lie = Cake.begin(); Lie!= Cake.end(); Lie++)
#define all(x) begin(x), end(x)

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;


bool check(vector<double>& arr, double d, double t){

    double prev = -1;
    for(int i=0;i < arr.size();i++){
        if(i == 0)
            prev = max(0.0, arr[i] - d);
        else{
            if(prev + t > arr[i] + d) // if we have to take more than d jumps
                return false;

            prev = max(arr[i] - d, prev + t);
        }
    }

    return true;

}


void solve()
{
    ll n;
    double t;

    cin >> n >> t;

    vector<double> arr(n);

    for(double & x: arr) cin >> x;

    sort(all(arr));

    double lo = 0.0, hi = 1000000000;

    double res; 
    while(hi - lo >= EPS){
        double mid = lo + (hi - lo)/2;

        if(check(arr,mid,t)){
            hi = mid;
            res = mid;
        }
        else{
            lo = mid;
        }
    }

    cout << fixed << setprecision(4) << res << endl;
	
}

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;
    cin>>t;

    while(t--)
        solve();

    return 0;
}

