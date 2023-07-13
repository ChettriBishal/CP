class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i < n;i++){
            dp[i][i] = true;
        }
        
        int lps = 1;
        int lo = 0;
        
        for(int j=1;j < n;j++){ // along column
            for(int i=j-1;i >=0;i--){ // along row
                
                if(s[i] == s[j]){
                    
                    if(j - i  == 1 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(lps < j - i + 1){
                            lps = j - i + 1;
                            lo = i;
                        }
                    }
                    
                }
                
            }
        }       
        
        return s.substr(lo, lps);
    }
};
/* dry run on paper
Input: s = "babad"
Output: "bab"
*/
