/* Top Down approach --> Recursion + Memoization */
#include<iostream>
#include<climits>
#include<map>
using namespace std;

map<int,int> dp;

int minsteps(int n)
{
    if(n == 1)
        return 0;
    if(dp[n])
        return dp[n];

    int res = INT_MAX;
    if(n%3 == 0)
        res = min(res, minsteps(n/3));
    if(n%2 == 0)
        res = min(res, minsteps(n/2));
    res = min(res,minsteps(n-1));

    return dp[n] = res +1; // one step to go from current problem to the sub-problem
}

int main()
{
    int n;
    cin>>n;
    int res = minsteps(n);
    printf("The minimum no of steps to reach from %d to 1 is: %d\n ",n,res);

    return 0;
}
