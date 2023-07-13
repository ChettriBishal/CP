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

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);

    for(auto &x: wt) cin >> x;

    vector<int> cnt(20,0);

    for(auto &x: wt){
        cnt[log2(x)]++;
    }

    int space_left = w;
    int height = 1;

    // max width upto 10^6
    // log2(10^6) upto 19
    for(int i=0;i < n;i++){
        int largest = -1;
        for(int j= 19;j >=0;j--){
            if(cnt[j] && (1 << j) <= space_left){
                largest = j;
                break;
            }
        }
        if(largest == -1){
            space_left = w;
            height++;
            for(int j=19;j >= 0;j--){
                if(cnt[j] && (1 << j) <= space_left){
                    largest = j;
                    break;
                }
            }
        }
        space_left -= (1 << largest);
        cnt[largest]--;
    }

    cout << height << endl;
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

