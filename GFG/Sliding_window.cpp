/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
*/
Class Solution{
 public:
// sliding window 
    int maximumSumSubarray(int k, vector<int> &a , int n){
        int res =0; // to store the initial window sum of size k
        for(int i = 0;i<k;i++){
            res += a[i];
        }
        int cursum = res;
        for(int i =k;i<n;i++){
            cursum = (cursum - a[i-k]+a[i]);
            res = max(res,cursum);
        }
        return res;
    }
};

/* 
Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700

Explanation:
Arr3  + Arr4 =700,
which is maximum.
*/

