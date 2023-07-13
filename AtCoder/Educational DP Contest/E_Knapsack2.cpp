#include<iostream>
#include<vector>
#define inf 1e9+3
using namespace std;
typedef long long ll;

// weight value structure 
struct wv{
    int wt; // weight 
    int val; // value
};

/*
dp[i][v] --> minimum sum of weights selected out of the first "i" items such that sum of values of selected items is "v"

Understand here dp[i][v] = weight

Recurrence relation
dp[i][v] --> dp[i-1][v] // when the current item is not included
         --> wt[i] + dp[i-1][v-v_i] // on including the current item
*/

void solve(vector<wv> & vec,int N,int W)
{
    ll Maxval = N * 1000;
    ll dp[N+1][Maxval+1]; // one based indexing

    for(ll val =0; val <= Maxval; val++){
        dp[1][val] = inf;
    }

    dp[1][0] = 0; // when it's not included

    dp[1][vec[1].val] = vec[1].wt;


    for(int i =2 ;i <= N;i++){
        for(ll v = 0; v <= Maxval ; v++){ // here we iterate over the range of values 
            dp[i][v] = dp[i-1][v]; // on excluding the current item  
            if(vec[i].val > v) 
                continue;
            dp[i][v] = min(dp[i][v], vec[i].wt + dp[i-1][v - vec[i].val]);
        }
    }

    ll res = 0;
    for(ll val = 0; val <= Maxval; val ++){
        if(dp[N][val] <= W)
            res = val;
    }

    cout<<res<<endl;

}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int N, W;
    cin>>N>>W;
    vector<wv> vec(N+1);
    for(int i=1 ;i <=N;i++){
        cin>>vec[i].wt >> vec[i].val;
    }

    solve(vec, N, W );

    return 0;
}


