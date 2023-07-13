class Solution {
public:
    int nthUglyNumber(int n) {
        // pointers for all three numbers
        int two = 0;
        int three = 0;
        int five = 0;
        
        vector<int> result;
        
        result.push_back(1);
        
        while(result.size() < n){
            int a = result[two] * 2;
            int b = result[three] * 3;
            int c = result[five] * 5;
            
            int m = min({a,b,c});
            
            result.push_back(m);
            
            if(a == m)
                two++;
            
            if(b == m)
                three++;
            
            if(c == m)
                five++;
        }
        
        return result.back();
    }
};
