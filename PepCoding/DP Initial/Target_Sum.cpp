#include<iostream>
#include<vector>
using namespace std;


bool possible(vector<int> & wt, int n, int tar){

    vector<vector<bool>> dp(n+1,vector<bool>(tar+1,false));

    for(int i=0;i <= n;i++) 
        dp[i][0] = true;

    for(int i= 1;i <= n;i++){
        for(int j=0;j <= tar;j++){
            dp[i][j] = dp[i-1][j];
            int val = wt[i-1];
            if(j >= val) // including the i-1th item 
                dp[i][j] = dp[i][j] || dp[i-1][j-val];
        }
    }

    return dp[n][tar];

}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n;
    cin >> n;
    vector<int> wt(n);

    for(auto &x: wt) cin >> x;

    int tar;
    cin >> tar;

    bool ok = possible(wt,n,tar);

    if(ok) cout <<"true";
    else cout <<"false";


    return 0;

}
