class Solution {
public:
    int res = 0;
    int seen = 0; 
    int countArrangement(int n,int pos =1) {
        if(n < 4) return n;
        
        if(pos > n) return res++;
        
        for(int i=1;i <= n;i++){
            int bit = (1 << i);
            if(!(seen & bit) && (i % pos == 0 || pos % i == 0)){
                seen ^= bit; // marking as seen
                countArrangement(n,pos+1);
                seen ^= bit; // backtracking
            }
        }
        return res;
    }
};
// https://leetcode.com/problems/beautiful-arrangement/
