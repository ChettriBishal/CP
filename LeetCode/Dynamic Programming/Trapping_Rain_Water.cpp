/* DP SOLUTION */

class Solution {
public:
    // dp solution
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxleft(n,0), maxright(n,0);
        maxleft[0] = height[0];
        maxright[n-1] = height[n-1];
        
        for(int i=1;i < n;i++){
            maxleft[i] = max(maxleft[i-1],height[i]);
        }
        for(int i=n-2;i >=0;i--){
            maxright[i] = max(maxright[i+1],height[i]);
        }
        
        int res = 0;
        
        for(int i=1;i < n-1;i++){
            res += min(maxleft[i], maxright[i]) - height[i];
        }
        
        return res;
    }
};
/*****************************************************************************/
/* TWO POINTERS */

class Solution {
public:
    // two pointer approach 
    int trap(vector<int>& height) {
        
        int res = 0;
        
        int leftmax = 0, rightmax = 0;
        
        int left = 0, right = height.size()-1;
        
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax) leftmax = height[left];
                else res += (leftmax - height[left]);
                left++;
            }
            else{
                if(height[right] >= rightmax) rightmax = height[right];
                else res += (rightmax- height[right]);
                right--;
            }
        }
        
        return res;
    }
};
