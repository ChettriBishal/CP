#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// iterative dp implementation
// dp[i][W]

// first dimension ---> first i items
// second dimension --> capacity of knapsack

ll knapsack(vector<pair<int,int>>& vec,int n,int W)
{
   ll dp[n+1][W+1]; // dp matrix 1 based index


   // setting the base case
   for(int w  = 0;w <= W; w++) // for any value other than the weight of the item 
       dp[1][w] = 0;

   dp[1][vec[1].first] = vec[1].second;  // dp(1,x) = value1 if( x == W1 )

   for(int i=2;i<=n;i++){
       for(int w = 0; w <= W; w++){
           // if we exclude the current item
           dp[i][w] = dp[i-1][w];

           if(w-vec[i].first < 0)  // if the weight of the current item is greater than the capacity
                continue;

           // or try including the current item 
            dp[i][w] = max(dp[i-1][w], vec[i].second + dp[i-1][w-vec[i].first] );
       }
   }

   return *max_element(dp[n], dp[n]+W+1);

}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n,W;
    cin>>n>>W;
    vector<pair<int,int>> vec(n+1);

    for(int i=1;i<=n;i++){
        cin>>vec[i].first >> vec[i].second;
    }

    cout<<knapsack(vec,n,W)<<endl;

    return 0;
}
