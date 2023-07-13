class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        return count_if(arr1.begin(),arr1.end(),[&](int val1){
           return all_of(arr2.begin(),arr2.end(),[&](int val2){
                return abs(val1 - val2) > d;
            });
        });
    }
};
