class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> cnt;
        
        for(string &s: cpdomains){
            
            int pos = s.find(" "); 
            int count = stoi(s.substr(0,pos));
            
            cnt[s.substr(pos+1)] += count;
            
            for(int i = pos +1;i < s.size(); i++)
                if(s[i] == '.')
                    cnt[s.substr(i+1)] += count;
        }
        
        vector<string> result;
        
        for(auto &p: cnt){
            result.push_back(to_string(p.second) + " " + p.first);
        }
        
        return result;
    }
};
