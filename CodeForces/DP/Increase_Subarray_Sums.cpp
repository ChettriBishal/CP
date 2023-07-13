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
using namespace std;
// template<typename T>
//using ordered_set= tree<T, null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
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

template<typename T> // to display 2D vector
ostream& operator << (ostream &ostream,const vector<vector<T>> &vec){
    for(auto &row: vec){
        for(auto &el: row){
            cout << el <<" ";
        }
        cout <<"\n";
    }
    return ostream;
}

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

#define int ll

void solve()
{
    int n,x;
    cin >> n >> x;
    vector<int> arr(n+2,0);

    int maxval = INT_MIN;
    for(int i=1;i <= n;i++){
        cin >> arr[i];
        maxval = max(maxval ,arr[i]);
        arr[i] += arr[i-1];
    }
    maxval = max(maxval, arr[n]);

    vector<int> mx(n+2,INT_MIN);
    mx[0] = maxval;

    for(int i=0;i <= n;i++){
        for(int j=i+1;j <= n;j++){ // maxsubarray sum for every possible subarray (contiguous)
            mx[j-i] = max(mx[j-i], arr[j] - arr[i]);
        }
    }

    for(int k =0;k <= n;k++){
        int val = 0;
        for(int j =1;j <= n;j++){
            val = max(val, mx[j] + min(k,j) *x); 
        }
        cout << val <<" ";
    }
    cout  <<endl;
}
//  mx[j] + min(k,j) *x
// we may / may not include all k elements so we iterate over all possible lengths 
// and include only that length that contributes to the highest sum

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

// https://codeforces.com/contest/1644/problem/C
