class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int > freq;
        
        int res = 0;
        
        for(auto &s: nums)
            freq[s]++;
        
        for(auto & [s, frq]: freq){
            if(target.find(s) == 0){
                if(s + s == target)
                    res += frq * (frq-1); // permutation (arrangement) 
                else
                    res += frq * freq[target.substr(s.length())];
            }
        }
        
        return res;
    }
};
