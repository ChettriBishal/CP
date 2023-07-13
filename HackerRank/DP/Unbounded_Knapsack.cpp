#include<iostream>
#include<vector>
#include<algorithm>
//#include"bistimulus.h"

using namespace std;

/*
Unbounded knapsack problem
Note that we use 1D array here which is different from classical knapsack where we used 2D array. 
Here number of items never changes. We always have all items available.

dp[i] = 0
dp[i] = max(dp[i], dp[i-wt[j]] + val[j] 
                   where j varies from 0 
                   to n-1 such that:
                   wt[j] <= i

result = d[W]

*/

void solve()
{
    int n,tar;
    cin >> n >> tar;
    vector<int> arr(n);
    for(int &x: arr) cin >>x;

    vector<int> dp(tar+1,0);

    for(int w=1;w <=tar;w++){ // for every weight less than or equal to target
        for(int j=0;j < n;j++){ // iterating over array for every weight
            if(arr[j] <= w)
                dp[w] = max(dp[w],arr[j]+ dp[w-arr[j]]);
        }
    }

    //debug(arr);
    //cout<<endl;
    //debug(dp);
    cout << dp[tar] <<"\n";

}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;

}
