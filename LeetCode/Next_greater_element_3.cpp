class Solution {
public:
    // same as next permutation 
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int k;
        for(k = s.size() -2 ; k >=0; k--)
            if(s[k] - '0' < s[k+1] - '0')
                break;
        if(k < 0)
            reverse(s.begin(), s.end());
        else{
            int i;
            for(i= s.size()-1;i> k;i--)
                if(s[i]-'0' > s[k]-'0')
                    break;
            swap(s[i],s[k]);
            reverse(s.begin()+k+1, s.end());
        }
        if(stol(s) < 0 || stol(s) > INT_MAX)
            return -1;
        if(stol(s) > n)
            return (int) stoi(s);
        else
            return -1;
    }
};
