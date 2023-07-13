class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001,0);
        int maxe = INT_MIN;
        for(auto & k: arr1) {
            cnt[k]++;
            maxe = max(k, maxe);
            
        }
        int g = 0;
        for(auto &k: arr2 ){
            while(cnt[k] -- ){
                arr1[g++] = k;
            }
        }
        for(int i=0;i<=maxe;i++){
            while(cnt[i]-- > 0){
                arr1[g++] = i;
            }
        }
    
        return arr1;
       
    }
};
