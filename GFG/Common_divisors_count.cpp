class Solution {
  public:
    long long int commDiv(long long int a,long long int b) {
        while(a){
            b = b%a;
            swap(a,b);
        }
        // b is the gcd
        int res = 0;
        for(int i=1;i*i<=b;i++){
            if(b % i == 0){
                if( b/i == i)
                    res++;
                else{
                    res += 2; // both n/i and i are divisors
                }
            }
        }
        return res;
    }
};
