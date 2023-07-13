class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        --n; 
        int carry=1;
        stack<int> gg;
        do{

            int k = (digits[n] + carry) %10;
            gg.push(k);
            carry = (digits[n] + carry) /10;
            n--;
        }while( n>=0);

        if(carry > 0)
            gg.push(carry);
        
        vector<int> res;
        
        
        while(! gg.empty()){
            //cout<<gg.top()<<" "; 
            res.push_back(gg.top());
            gg.pop();
        }
        return res;
    }
};
