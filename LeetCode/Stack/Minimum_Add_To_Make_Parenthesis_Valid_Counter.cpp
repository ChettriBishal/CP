class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, right =0;
        for(auto &x: s){
            if(x == ')'){
                if(left > 0)
                    left--;
                else
                    right++;
            }
            else
                left++;
        }
        return (left + right);
    }
};
