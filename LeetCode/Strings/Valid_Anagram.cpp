class Solution {
public:
    void calcfreq(unordered_map<char,int>& mp, string& s){
        for(const auto& x: s){
            mp[x] ++;
        }
    }
    bool isAnagram(string s, string t) {
        if(s.size() < t.size()) swap(s,t);
        unordered_map<char,int> freqS;
        unordered_map<char,int> freqT;
        
        calcfreq(freqS,s);
        calcfreq(freqT,t);
        for(const auto & el: freqS){
            char ch = el.first;
            if(freqT.find(ch) == freqT.end())
                return false;
            else{
                if( freqT[ch] != freqS[ch])
                    return false;
            }
        }
        return true;
    }
};
