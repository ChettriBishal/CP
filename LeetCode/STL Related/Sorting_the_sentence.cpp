class Solution {
public:
    static bool comp(string& a, string &b){
        int last_index = a.find_last_not_of("0123456789");
        string index_a  = a.substr(last_index +1);
        
        last_index = b.find_last_not_of("0123456789");
        string index_b = b.substr(last_index +1);
        
        return stoi(index_a) < stoi(index_b); // sorting on the basis of index 
        
    }
    
    string sortSentence(string s) {
        vector<string> words; // to store the words 
        
        stringstream ss(s);
        string tok;
        
        while(ss >> tok){ // extracting words 
            words.push_back(tok);
        }
        
        sort(words.begin(), words.end(),comp);
        
        string result = "";
        
        for(auto &st: words){
            int last_index = st.find_last_not_of("0123456789");
            result += st.substr(0, last_index+1) + ' ';
        }
        
        result.pop_back();
        
        return result;
    }
};
