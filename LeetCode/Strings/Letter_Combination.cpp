class Solution {
public:
    vector<string> res;
    vector<string> keys{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void generate(string digits,int i,string s)
    {
       if(s.size() == digits.size()){
           res.push_back(s);
           return ;
       } 
        int digit = digits[i] - '0';  
        if(digit == 1 || digit == 0) // skipping this 
            generate(digits,i+1,s);
        for(auto k: keys[digit])
            generate(digits,i+1,s+k);
        return;
    }
    vector<string> letterCombinations(string digits) {
        
        int n = digits.size();
        if(n == 0) return {};
        string ok = "";
        generate(digits,0,ok);
        return res;
    }
};
