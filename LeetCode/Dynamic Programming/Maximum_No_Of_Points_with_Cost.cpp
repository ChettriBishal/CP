class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> pre(n,0);
        
        for(int i=0; i<n;i++)
            pre[i] = points[0][i];
        
        for(int i=1;i< m;i++){
            vector<long long> lft(n,0), rgt(n,0), curr(n,0);
            
            lft[0] = pre[0];
            
            for(int j=1;j < n;j++){
                lft[j] = max(pre[j], lft[j-1] -1);
            }
            
            rgt[n-1] = pre[n-1];
            
            for(int j =n-2; j>=0;j--){
                rgt[j] = max(pre[j] , rgt[j+1]-1);
            }
            
            for(int j =0;j < n;j++)
                curr[j] = points[i][j] + max(lft[j], rgt[j]);
            
            pre = curr;
        }
        
        return *max_element(pre.begin(), pre.end());
    }
};
