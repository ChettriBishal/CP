class Solution {
public:
    string truncateSentence(string s, int k) {
        string word, res = "";
        stringstream ss(s);
        while(k--){
           ss>> word;
            res += word;
            if(k >= 1)
                res+= " ";
        }
        
        return res;
    }
};
