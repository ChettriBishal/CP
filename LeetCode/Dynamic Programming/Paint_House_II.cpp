/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
Return the minimum cost to paint all houses.

 

Example 1:

Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
Example 2:

Input: costs = [[1,3],[2,4]]
Output: 5
 

Constraints:

costs.length == n
costs[i].length == k
1 <= n <= 100
2 <= k <= 20
1 <= costs[i][j] <= 20
 

Follow up: Could you solve it in O(nk) runtime?
*/

// O(n * k ^2) 

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int cols = costs[0].size(); // no of colors (columns)
        vector<int> dp(cols, 0);
        
        int n = costs.size();
        
        for(int i=1;i <= n;i++){ // houses
            vector<int> curr(cols,0);
            for(int j =0;j < cols;j++){ // color current row
                
                curr[j] = costs[i-1][j];
                int add = INT_MAX; // minimum value to add from the previous row
                
                for(int k= 0;k < cols;k++){ // color previous row
                    if(k != j)
                        add = min(add, dp[k]);
                }
                
                curr[j] += add;
            }
            
            dp.clear();
            dp = curr;
        }
        
        return *min_element(dp.begin(),dp.end());
    }
};

// O(n * k)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        for(int i=1;i < n;i++){ // houses
            int mincol = -1, secondmincol = -1;
            
            for(int j = 0;j < k;j++){ // select the minimum and second minimum cost from previous row with respect to their colors
                int cost = costs[i-1][j];
                
                if(mincol == -1 || cost < costs[i-1][mincol]){
                    secondmincol = mincol;
                    mincol = j;
                }
                else if(secondmincol == -1 || cost < costs[i-1][secondmincol]){
                    secondmincol = j;
                }
            }
            
            // update the current row 
            for(int j = 0;j < k;j++){
                if(j == mincol){
                    costs[i][j] += costs[i-1][secondmincol];
                }
                else{
                    costs[i][j] += costs[i-1][mincol];
                }
            }
        }
        
        return *min_element(costs[n-1].begin(),costs[n-1].end());
        
    }
};
