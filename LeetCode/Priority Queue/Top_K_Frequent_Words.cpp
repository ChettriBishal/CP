class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(auto &x: words) 
            cnt[x]++;
        
        auto comp = [&](const pair<string,int> & a, const pair<string,int> & b){
            if(a.second == b.second)
                return a.first < b.first; // lexicographical
            return a.second > b.second;
            
        };
        
        typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp)> my_priority_queue;
        
        my_priority_queue pq(comp); 
        
        
        for(auto &two: cnt){
            pq.push(two);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> result(pq.size());
        
        for(int i=pq.size()-1; i>= 0;i--){
            result[i] = pq.top().first;
            pq.pop();
        }
        
        return result;
    }
};
