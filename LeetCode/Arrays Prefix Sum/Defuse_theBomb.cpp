class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> pre(n,0);
        
        if(k == 0)
            return pre;
        bool rev = false;
        
        if(k < 0){ // sum of previous k elements 
            reverse(code.begin(),code.end());
            k = -k;
            rev = true;
        }
        
        pre[0] = code[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + code[i];
        }
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(i + k <n)
                res[i] = pre[i+k] - pre[i];
            else{
                res[i] = pre[n-1] - pre[i] + pre[(i+k) %n];
            }
        }
        if(rev) reverse(res.begin(),res.end()); // if it was reversed then the result must be reversed
        return res;
    }
};
