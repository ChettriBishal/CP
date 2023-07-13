class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> temp = generate(n);
        
        vector<int> result( 1 << n);

        for(int i=0; i< (1 <<n);i++){
            result[i] = stoi(temp[i],0, 2);
        }
        
        return result;
    }
    
    vector<string> generate(int n){
        
        if(n == 1){ // base case
            vector<string> res{"0","1"};
            return res;
        }
        
        vector<string> res = generate(n-1); 
            
        vector<string> nres;
        
        for(int i=0; i< res.size();i++){ // left to right
            nres.push_back("0" + res[i]);
        }
        
        for(int i=res.size()-1; i>=0 ;i--){ // right to left
            nres.push_back("1" + res[i]);
        }
        
        return nres;
    }
};
