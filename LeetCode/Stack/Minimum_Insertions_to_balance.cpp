class Solution {
public:
    int minInsertions(string s) {
        stack<char> brack;
        
        int cnt = 0;
        int n = s.length();
        
        for(int i=0;i< n;i++){
            if(s[i] == '('){
                brack.push(s[i]);
            }
            else{
                if(!brack.empty())
                    brack.pop();
                else 
                    cnt++;
                if(i+ 1 < n && s[i] == s[i+1])
                    i++;
                else
                    cnt++;
            }
        }
        
        return brack.size() * 2 + cnt; // brack only contains opening brackets 
    }
};
// 1 opening bracket requires two closing ones to balance
// so we multiply by 2 

// Dry run over test cases for better clarity 
