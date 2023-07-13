class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> check;
       
        stack<int> gon; // to store elements encountered so far from back
        int greater = -1;
        for(int i = n-1;i>= 0;i--){
            int curr = nums2[i];
            while(!gon.empty() && curr > gon.top())
                gon.pop();
            greater = gon.empty()?-1: gon.top();
            check[curr] = greater;
            gon.push(nums2[i]); 
        }

        n = nums1.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]= check[nums1[i]];
        }
        return res;
    }
};
