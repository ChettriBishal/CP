/*
There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.


Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: costs = [[7,6,2]]
Output: 2
 

Constraints:

costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20

*/

/* Solution 1 dp O(n) space*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> red(n+1,0), green(n+1,0), blue(n+1,0);
        
        for(int i=1;i <= n;i++){
            red[i] = costs[i-1][0] + min(green[i-1], blue[i-1]);
            blue[i] = costs[i-1][1] + min(red[i-1], green[i-1]);
            green[i] = costs[i-1][2] + min(red[i-1], blue[i-1]);
        }
        
        return min({red[n], blue[n], green[n]});
    }
};

/* Recursion + Memoization */

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> costs;
    
    int minCost(vector<vector<int>>& costs) {
        dp.resize(costs.size()+1, vector<int>(3,-1));
        this->costs = costs;
        
        return min({dfs(0,0), dfs(0,1), dfs(0,2)});
    }
    
    int dfs(int i, int col){
        if(dp[i][col] != -1)
            return dp[i][col];
        
        int totcost = costs[i][col];
        
        if(i == costs.size()-1){
            
        }else if(col == 0){ // red
            totcost += min(dfs(i+1,1),dfs(i+1,2));
        }
        else if(col == 1){ // blue
            totcost += min(dfs(i+1,0), dfs(i+1,2));
        }
        else if(col == 2){ // green
            totcost += min(dfs(i+1,0), dfs(i+1,1));
        }
        
        return dp[i][col] = totcost;
    }
    
};
