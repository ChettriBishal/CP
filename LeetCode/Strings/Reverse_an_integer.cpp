class Solution {
public:
    int reverse(int x) {
       
        string s= to_string(x);
        bool neg = false;
        if(s[0] == '-'){
            neg = true;
        }

        std::reverse(s.begin(),s.end());
        if(neg) s.insert(s.begin(),'-');
        stringstream ok(s);
        long long int res = 0;
        ok >> res;
        if(res < INT_MIN || res > INT_MAX) return 0;
        return res;
    
    
    }
};
