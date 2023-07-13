class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        
        for(int i=0;i < n;i++){
            arr[i] = {nums[i], i};
        }
        
        vector<int> res(n,0);
        
        merge_sort(arr,res,0, n-1);
        
        return res;

    }
  
    void merge_sort(vector<pair<int,int>>& arr, vector<int>& res, int l, int r){
        if(l < r){
            int mid = (l + r)/2;
            merge_sort(arr, res, l, mid);
            merge_sort(arr, res, mid+1, r);
            merge(arr, res, l,r);
        }
    }
  
    void merge(vector<pair<int,int>>& arr, vector<int>&res, int l, int r){
        int mid = (l + r)/2;
        int i = l, j = mid+1, k = 0;
      
        vector<pair<int,int>> temp(r - l + 1); // merged 
        
        int numElemsRightLessThanLeft = 0;
      
        while(i <= mid && j <= r){
            if(arr[i].first > arr[j].first){
                numElemsRightLessThanLeft++;
                temp[k++] = arr[j++];
            }
            else{
                res[arr[i].second] += numElemsRightLessThanLeft;
                temp[k++] = arr[i++];
            }
        }
      
        while(i <= mid){
            res[arr[i].second] += numElemsRightLessThanLeft;
            temp[k++] = arr[i++];
        }
      
        while(j <= r){
            temp[k++] = arr[j++];
        }
        
        for(int i = l;i <= r;i++)
            arr[i] = temp[i-l];
    }
};
