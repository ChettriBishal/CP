class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        for(int r=0;r < min(n,k);r++)
            pq.push({matrix[r][0], r, 0});
        
        int res;
        
        for(int i=1;i <= k;i++){
            auto top = pq.top(); pq.pop();
            res = top[0];
            int r = top[1], c = top[2];
            if(c + 1 < n)
                pq.push({matrix[r][c+1],r,c+1});
        }
        
        return res;
    }
};
