class Solution {
public:
    void freqcalc(int* freq, string s){
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }
    }
    bool isAnagram(string s, string t) {
        if(s.size() < t.size())
            swap(s,t);
        int freqS[26],freqT[26];
      
        memset(freqS,0,sizeof(freqS));
        memset(freqT,0,sizeof(freqT));
      
        freqcalc(freqS,s);
        freqcalc(freqT,t);
      
        for(int i=0;i<s.size();i++){
            freqS[s[i]-'a']--;
            freqT[s[i]- 'a']--;
        }
      
       // if the strings have the same characters in the same quantity then the freq array
        // for both the strings must have all mapped to zero
      
        for(int i=0;i<26;i++){
            if(freqS[i] != 0 || freqT[i] != 0)
                return false;
        }
        return true;
    }
};
