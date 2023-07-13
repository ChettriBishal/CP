class Solution {
public:
     int eval(int a,int b,char c){
        switch(c){
            case '/': return a/b; break;
            case '*': return a*b; break;
            case '+': return a+b; break;
            case '-': return a-b; break;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> bis;
        for(auto & it: tokens){
            if(it != "+" && it != "-" && it != "/" && it != "*"){
                bis.push(stoi(it));
            }
            else{
                int second = bis.top(); bis.pop();
                int first = bis.top(); bis.pop();
                first = eval(first,second,it[0]);
                bis.push(first);
            }
        }
        return bis.top();
    }
};
