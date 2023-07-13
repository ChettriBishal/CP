class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size(); 
        vector<int> temp(26,0), freq(26,INT_MAX);
        for(int i=0;i<n;i++){
            for(const char& c: words[i]){
                temp[c - 'a'] ++;
            }
            for(int i=0;i<26;i++){
                freq[i] = min(freq[i], temp[i]);
            }
            std:: fill(temp.begin(),temp.end(),0); // for another word 
        }
        vector<string> res;
        for(int i=0;i<26;i++){
            char c = i+'a';
            string s(1,c);    // string of size 1 (size,character)
            while(freq[i] --){
               res.push_back(s); 
            }
        }
        
        return res;
    }
};
