class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int dum =0;
        vector<int> pre(arr.size());
        pre[0] = arr[0];
        for(int i=1;i<arr.size();i++){ // creating a prefix sum array of xor
            pre[i] = pre[i-1] ^ arr[i];
        }
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int temp;
            if(l == 0) 
                temp = pre[r];
            else 
                temp = pre[r] ^ pre[l-1];
            res.push_back(temp);
        }
        return res;
    }
};
