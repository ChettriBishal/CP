class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> bis;
        int cnt = 0;
        for(char &c: s){
            if(c == '(')
                bis.push(c);
            else{
                if(!bis.empty())
                    bis.pop();
                else
                    cnt++;
            }
        }
        int res= max((int)bis.size(),cnt +(int) bis.size());
    
        return res;
        
    }
};
