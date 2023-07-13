class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> mpkeys; // keys which are already mapped
        for(int i=0;i<s.size();i++){

            // if the current character s[i] isn't mapped to any other character
            // also if the t[i] isn't a value for any key from s[i]
            if(mp.find(s[i]) == mp.end() && mpkeys.find(t[i]) == mpkeys.end()){
                mp[s[i]] = t[i];
                mpkeys.insert(t[i]);
            }
            else{
                if(mp[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
