class Solution {
public:
    int getSum(int a, int b) {
        int res =0;
        if(a== 0 || b== 0)
            return max(a,b);
        unsigned int carry = 0;  // to denote carry
        unsigned int sum =0;
        while(b){
          // cout<<a << " "<<b<<" "<<sum<<endl;
           sum = a ^ b;
           carry = a & b;
           b = carry << 1;
           a = sum; 
        }
        
        return sum;
        
    }
};
/* try with a = 13 and b = 10 
dry run over binary 
*/
