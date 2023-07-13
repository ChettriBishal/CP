class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for(int i=0;i<words.size();i++){
            if(match(words[i], pattern))
                result.push_back(words[i]);
        }
        
        return result;
    }
    
    bool match(string & word, string& pattern){
        unordered_map<char,char> m1, m2;
        // m1 maps word's characters to pattern's
        // m2 maps pattern's characters to word's 
        
        for(int i=0;i<word.size();i++){
            
            if(m1.find(word[i]) == m1.end() && m2.find(pattern[i]) == m2.end()){
                m1[word[i]] = pattern[i];
                m2[pattern[i]] = word[i];
            }
            else{
                if(m1[word[i]] != pattern[i])
                    return false;
                if(m2[pattern[i]] != word[i])
                    return false;
            }
        }
        
        return true;
    }
};
