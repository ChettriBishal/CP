class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        
        for(auto &x: nums)
            cnt[x]++;
        
        vector<int> result;
        
        priority_queue<pair<int,int>> pq;
        // first = frequency and second = element
        
        for(auto &two: cnt){
            pq.push({two.second, two.first});
            if(pq.size() > cnt.size() - k){
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return result;
    }
};
