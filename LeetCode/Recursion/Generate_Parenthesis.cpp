class Solution {
public:
    vector<string> store;
    void generate(string s,int i, int n,int op,int cl){
        if(i == 2*n){
           store.push_back(s); 
        }
        if(op < n){
            generate(s+'(',i+1,n,op+1,cl);
        }
        if(cl < op){
            generate(s+')',i+1,n,op,cl+1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
    
        string s = "";
        generate(s,0,n,0,0);
        return store;
    }
};
