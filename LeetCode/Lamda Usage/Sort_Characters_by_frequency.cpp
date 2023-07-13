class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> cnt;
      
        for(char &x: s) cnt[x]++;
      
        sort(s.begin(), s.end(),[&](const char& a,const char& b){
            if(cnt[a] == cnt[b])
                return a < b;
            return cnt[a] > cnt[b];
        });
      
        return s;
    }
};
