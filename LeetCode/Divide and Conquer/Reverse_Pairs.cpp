class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() -1);
    }
    int merge_sort(vector<int>& nums,int start,int end){
        
        int cnt = 0; //  number of reverse pairs
        
        if(start >= end)
            return 0;

        int mid = (start + end)/2;
        cnt += merge_sort(nums, start,mid);
        cnt += merge_sort(nums, mid+1, end);

        for(int i=start, j= mid + 1;i <= mid;i++){
            while(j <= end && nums[i] > 2 *1LL* nums[j]) j++;

            cnt += (j - (mid + 1));
        }
        
        merge(nums, start,end);

        
        return cnt;
    }
    void merge(vector<int> & arr, int start, int end){
        int mid = (start + end)/2;
        int i = start, j = mid+1 , k = 0;
        
        vector<int> temp(end - start + 1);
        
        
        int add = 0;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid)
            temp[k++] = arr[i++];
        
        while(j <= end)
            temp[k++] = arr[j++];
        
        for(int i=start;i <= end;i++){
            arr[i] = temp[i - start];
        }

    }
};
