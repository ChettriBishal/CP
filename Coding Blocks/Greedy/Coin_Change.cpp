// works for indian denomination 
// for others you'd require DP
#include<iostream>
#include<algorithm>
using namespace std;

int coins_needed(int* coins, int amount, int n)
{
    int cnt = 0;
    while(amount > 0){
        int ind = upper_bound(coins,coins+n,amount) - coins -1;
        if(ind != n || ind<0){
            amount -= coins[ind]; 
            cout<<coins[ind];
            if(amount > 0) cout<<" + ";
            cnt ++;
        }
    }
    cout<<endl;
    return cnt;
}

int main()
{
    // say we have coins for these values
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);
    int amount;
    cin>>amount;
    
    int req = coins_needed(coins,amount,n);

    cout<<"Coins needed: "<<req<<endl;

    return 0;

}
// taking upper_bound :
// if we have amount as 39 then we want 20 as the change for that instant 
// upperbound(39) = index of 50
// upper_bound(39)-1 = index of 20
