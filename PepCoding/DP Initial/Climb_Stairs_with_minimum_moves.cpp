#include<bits/stdc++.h>
using namespace std;

int jumpT(int i, int n, vector<int>& jumps, vector<int>& dp,int cnt =0)
{
    dp[n] = 0;
    
    for(int i= n-1;i >= 0;i--){
        for(int j = 1;j <= jumps[i] && j + i <= n; j++){
            dp[i] = min(dp[i], dp[i+j] + 1);
        }
    }
    
    return dp[0];

}

int main() {

  int n;
  cin >> n;

  vector<int> jumps(n);

  for (int i = 0; i < n; i++)
  {
    cin >> jumps[i];
  }

  vector<int> dp(n + 1, 0);
  
  for(auto &x: dp) x = 34; // assigning the largest value for dp

  int ans = jumpT(0, n, jumps, dp);

  if (ans < 30)
    cout << ans;
  else
    cout << "null";
}
