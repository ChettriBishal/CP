class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // O(n*logK)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int &num: nums){
            if(minHeap.size() < k)
                minHeap.push(num);
            else if(minHeap.size() == k){
                if(minHeap.top() < num){
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
        
        return minHeap.top();
    }
};
