/* A Frog 1 AtCoder Edu. DP*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x: a) cin>>x;
    unordered_map<int,int> dp;
    dp[0] = 0;// minimum cost to reach the first stone
    dp[1] = abs(a[1]- a[0]);  // only one way to reach second stone from first one
    for(int i=2;i<n;i++){
        int firstway = dp[i-1] + abs(a[i] - a[i-1]); // take one step
        int secondway = dp[i-2] + abs(a[i]- a[i-2]); // take two steps
        dp[i] = min(firstway ,secondway);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
