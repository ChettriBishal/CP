#include<iostream>
#include<vector>
using namespace std;


int getways(vector<int>& coins,int amount){

    //dp [i] --> no of ways to make amount i using the given set of coins
    vector<int> dp(amount+1,0);
    dp[0] = 1;
    
    for(int i = 0;i < (int) coins.size();i++){
        for(int am = 1;am <= amount;am++){
            if(am >= coins[i]){ // if it's possible to construct the amount am using coins[i]
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

    for(int &x: coins) cin >> x;

    int amt;
    cin >> amt;

    cout << getways(coins, amt) <<endl;

    return 0;

}
