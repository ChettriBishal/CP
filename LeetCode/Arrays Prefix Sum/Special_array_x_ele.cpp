class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> arr(1001, 0);
        int mx = -1;
        for(int & x: nums){
            arr[x]++;
            mx = max(mx, x);
        }
        for(int i= mx-1;i >= 1;i--){ // suffix sum array
            arr[i] += arr[i+1];
        }
        for(int i= 1 ; i<= mx;i++){
            if(i == arr[i])
                return i;
        }
        return -1;
    }
};
