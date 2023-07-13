class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        
        for(int i=1;i < intervals.size();i++){
            int currLow = intervals[i][0];
            int currHigh = intervals[i][1];
            
            int prevLow = res.back()[0];
            int prevHigh = res.back()[1];
            
            if(currLow >= prevLow && currLow <= prevHigh){ // overlapping
                res.pop_back();
                res.push_back({prevLow, max(currHigh, prevHigh)});
            }
            else{
                res.push_back({currLow, currHigh});
            }
        }
        
        return res;
    }
};
