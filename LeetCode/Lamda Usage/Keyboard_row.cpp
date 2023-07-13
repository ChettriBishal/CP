class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows{"qwertyuiop","asdfghjkl","zxcvbnm"};
        vector<string> ans;
        for(auto & str: words){
            string s = str;
            std::transform(str.begin(),str.end(),str.begin(),[](const unsigned char& c){
                               return tolower(c);
                           }); // to store as lower case characters so that we can check from the rows easily 
         
            unordered_set<char> ok(str.begin(),str.end());
           // check every row
            for(auto row: rows){
                bool yes = true;
                for(auto & c: ok){
                    if(row.find(c) == string::npos){
                        yes = false;
                        break;
                    }
                }
                if(yes){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
