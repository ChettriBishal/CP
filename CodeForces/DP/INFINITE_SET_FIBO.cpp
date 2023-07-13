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
constexpr int MOD = 1e9 + 7;

const int maxn = 2e5+ 3;

bool check(int x, set<int>& st){ // to check if it has been seen before
    if(x == 0) return false;
    if(st.find(x) != st.end()) 
        return true;
    if(x &1){
        x >>= 1;
        return check(x, st);
    }
    else{
        if(x % 4 != 0) return false;
        x >>= 2;
        return check(x,st);
    }
}


void solve()
{
    int n,p;
    cin >> n >> p;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    vector<int> dp(maxn);
    dp[0] = dp[1] = 1;

    for(int i=2;i < maxn;i++) // fibo series
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    for(int i=1;i < maxn;i++) // prefix sum of fibo series
        dp[i] = (dp[i] + dp[i-1]) % MOD;

    set<int> st;
    sort(arr.begin(),arr.end());
    for(auto &x: arr){
        if(!check(x,st)){
            st.insert(x);
        }
    }
    
    vector<int> useful(st.begin(),st.end());

    int res = 0;
    for(auto &x: useful){
        string s = bitset<32>(x).to_string();
        reverse(s.begin(),s.end());
        while(s.back() == '0')
            s.pop_back();
        int rem = p -  (int) s.length();
        if(rem < 0) 
            continue;
        debug(rem,dp[rem]);
        res  = (res + dp[rem]) % MOD;
    }

    cout << res <<"\n";
	
}
// example
// 1 4
// 1
// Ans: 7
// Those numbers less than 2^4 = 7 numbers
// len(1) = 1, p = 4
// dp[p - len(1)] = dp[4 - 1] = dp[3] = 7

signed main()
{
	#ifdef Bis
		freopen("input.txt","r",stdin);
	#endif
    io;
    int t = 1;

    while(t--)
        solve();

    return 0;
}
// https://codeforces.com/contest/1635/problem/D
