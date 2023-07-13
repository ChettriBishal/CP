class Solution {
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left= 0 , right= n-1 ;
        bool yes = false;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                yes = true;
                left = i;
                break;
            }
        }
        while(left > 0 && nums[left-1] == nums[left]) // 1 3 3 3 2
          left--; 
      
        for(int i= n-1;i>0;i--){
            if(nums[i] < nums[i-1]){
                yes = true;
                right = i;
                break;
            }
        }
        while(right < n-1 && nums[right+1] == nums[right]) // 1 5 7 6 6 6 6
          right++;  
       
        int mine = INT_MAX, maxe = INT_MIN;
        for(int i = left ;i<= right ;i++){
            mine = min(nums[i],mine);
            maxe = max(nums[i],maxe);
        }
      
        while(left > 0 && nums[left-1] > mine) 
          left--;
        while(right < n-1 && nums[right+1] < maxe) 
          right++;
       // cout<<left<<" "<<right<<endl;

        if(yes){
            return (right - left + 1);
        }
      
        return 0;
        
    }
};
