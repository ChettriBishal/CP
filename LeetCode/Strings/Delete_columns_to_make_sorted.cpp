class Solution {
public:
   
    bool checkord(string s){ // to check if the string is sorted lexicographically
        bool one = true;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] <= s[i+1]) continue;
            else{
                one = false;
                break;
            }
        }
        return one;
                
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        vector<string> ok(strs[0].size(),"");
        for(int i= 0;i<strs[0].size();i++){
            for(int j=0;j<n;j++)
                ok[i] += strs[j][i];
        }
        
        int res = 0;
        for(auto vec: ok){
            if(! checkord(vec)) {
                res++;
            }
        }
        return res;
        
        
    }
};
