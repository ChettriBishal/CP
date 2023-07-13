// Time O(n * n * tar * m)

class Solution {
public:
    int dp[101][101][21] = {};
    vector<int> houses;
    vector<vector<int>> cost;
    int m, n;
    int MAX = 1e8;
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->houses = houses;
        this->cost = cost;
        this->m = m, this->n = n;
        
        int res = dfs(target,0,0);
        
        return res == MAX? -1: res;
    }
    
  /* tar -> target
     h -> house no
     col -> color (column too :)
  */
    int dfs(int tar,int h, int col){
        if(h == m || tar < 0)
            return tar == 0 ? 0: MAX;
        
        if(dp[tar][h][col])
            return dp[tar][h][col];
        
        int ans = MAX;
        
        if(houses[h] == 0){ // we can color the house
            for(int k = 1; k <= n;k++){ // new color 
                ans = min(ans, cost[h][k-1] + dfs(tar - (col != k),h+1,k));
            }
        }
        else{
            ans = dfs(tar - (col != houses[h]),h+1,houses[h]);
        }
        
        return dp[tar][h][col] = ans;
    }
};

/* 
-> tar - (col !=k) 
-> this means we will reduce the number of neighbourhoods by 1 if we are using a different color for the next house wrt to the current one.

-> We add the cost only if the current house isn't painted ie houses[h] == 0
-> Else we do not add the cost still check if the current color is different than the previous, if yes reduce the no of neighbourhoods.  
-> Same for tar - (col != houses[h])

We derive time O(m * t * n * n) is the following: t ->target

What are the number of function calls we make?
- Number of possible unique states => m * t * n
- We have m * t * n function calls
How much time does each function call take?
- Well everything is constant time besides the loop to pick a color aka O(n) since n == color
- So O(n)
Multiply
(1) number of function calls * (2) work per function
time complexity = (m * t * n) * (n)

*/

