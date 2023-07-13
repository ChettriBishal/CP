#include<iostream>
#include<vector>
using namespace std;


int noofpermutations(vector<int>& coins,int amount){
    vector<int> dp(amount+1,0);

    dp[0] = 1;

    // loops are interchanged when compared to coin change combinations
    for(int am = 1;am <= amount;am++){
        for(int i=0;i < coins.size(); i++){
            if(am >= coins[i]){
                dp[am] += dp[am - coins[i]];
            }
        }
    }

    return dp[amount];

}

int main()
{

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n;
    cin >> n;

    vector<int> coins(n);

    for(int i=0;i < n;i++){
        cin >> coins[i];
    }

    int amount;
    cin >> amount;


    int res = noofpermutations(coins,amount);

    cout << res <<endl;

    return 0;

}
