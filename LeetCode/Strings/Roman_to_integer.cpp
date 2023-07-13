class Solution {
public:
    unordered_map<char,int> val= {
        pair<char,int> ('I',1),
        pair<char,int> ('V',5),
        pair<char,int> ('X',10),
        pair<char,int> ('L', 50),
        pair<char,int> ('C',100),
        pair<char,int> ('D', 500),
        pair<char,int> ('M',1000) 
        
    };
    
    int romanToInt(string s) {
        int n = s.length();
        int res =0;
        for(int i=0;i<n;i++){
           if(i+1 < n){
               if(val[s[i]] < val[s[i+1]])
                   res -= val[s[i]];
               else
                   res += val[s[i]];
           }
           else{
               res += val[s[i]];
           }
        }
        return res;
    }
};
