class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum =0;
        int n= arr.size();
        vector<int> pre(n+1,0);
        pre[1] = arr[0];
        for(int i=2;i<=n;i++)
            pre[i] = pre[i-1] + arr[i-1];
        sum += pre[n];
        int k = 3;
        for(int i=3;i<=n;i++){
            for(int j=k;j<=n;j++){
                sum += pre[j] - pre[j-k];
                
            }
            k+=2; // 3 --> 5 --> 7 incrementation
        }
        
        return sum;
    }
};
