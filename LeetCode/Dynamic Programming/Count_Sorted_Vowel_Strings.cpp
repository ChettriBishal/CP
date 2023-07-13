// O(n) space 
/* The number of strings of size k that start with a vowel v are 
the sum of the strings of size k-1 with whom we can add the vowel v from the beginning without breaking the order. */
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vows(5,1);

        while(--n){            
            for(int i=1;i < 5;i++){
                vows[i] += vows[i-1];
            }
        }      
        return accumulate(vows.begin(),vows.end(),0);
    }
};
// vows[i] --> number of sorted strings possible ending at ith vowel 


// O(n*k) space

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,0));
        
        for(int i=1;i <= n;i++){
            for(int k=1;k <= 5;k++){
                dp[i][k] = dp[i][k-1] + (i > 1 ? dp[i-1][k]: 1);
            }
        }
        
        return dp[n][5];
    }
};
/* 
dp[n][k] 

Number of strings of length n, taking the first k vowels

dp[i][k-1]... no of strings without taking the current vowel of length i

dp[i-1][k]... no of strings of length i -1 taking the current vowel

*/
