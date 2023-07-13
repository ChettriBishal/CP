/*
Given a integer number n, find largest sum of digits in all divisors of n.

Input:
n = 34
Output:
8

Explanation:
The divisors of 34 are: 1,2,17,34.
8 is the maximum digit-sum among all divisors. 
*/
class solution{
 public:
  int getsum(int n){ // to get the sum of the digits 
      int sum =0;
      while(n){
          sum += (n%10);
          n /=10;
      }
      return sum;
    }
    int getLargest(int n) {
        int res = INT_MIN;
        for(int i=1;i*i<=n;i++){
            if(n % i == 0){
                if( n/i == i){
                    res = max(res,getsum(i));
                }
                else{
                    res = max(max(getsum(i),res),getsum(n/i));
                }
            }
        }
        return res;
    }
};
