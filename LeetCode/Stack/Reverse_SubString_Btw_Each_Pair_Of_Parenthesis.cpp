class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                int start = st.top();
                st.pop();
                reverse(s.begin() + start +1, s.begin() + i);
            }
        }
        
        auto er = remove_if(s.begin(),s.end(), [] (char &c){
            return (c == ')' || c == '(');
        });
        
        s.erase(er,s.end());
        
        return s;
    }
};
