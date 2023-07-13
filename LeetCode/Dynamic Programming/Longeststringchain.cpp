class Solution {
public:
    
    // sort on the basis of length
    static bool comp(string & a, string & b){
        return a.size() < b.size();
    }
    
    // function to check if 'a' has one character less than 'b'
    bool check(string &a, string & b){ 
        
        int n = a.size(), m = b.size();
        
        if(n + 1 != m)
            return false;
        
        int i = 0, j= 0;
        
        while(j < m){
            if(i < n && a[i] == b[j]){
                i++, j++;
            }
            else{
                j++; // b is longer
            }
        }
        
        return (i == n && j == m);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp); 
        
        int n = words.size();
        
        vector<int> dp(n,1);
        
        // Same as LIS
        for(int i=0;i < n;i++){
            for(int j=0;j < i;j++){
                if(check(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};
