class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> brack;
        
        unordered_set<int> check;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                brack.push(i);
            }
            else if(s[i] == ')'){
                if(!brack.empty()){
                    brack.pop();
                }
                else{
                    check.insert(i);
                }
            }
        }
        
        while(!brack.empty()){
            //cout<<brack.top()<<" ";
            check.insert(brack.top());
            brack.pop();
        }
        
        for(int i=0;i<s.length();i++){
            if(check.find(i) == check.end())
                res += s[i];
        }
        
        return res;
    }
};
