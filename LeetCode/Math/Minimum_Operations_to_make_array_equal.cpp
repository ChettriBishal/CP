class Solution {
public:
    int minOperations(int n) {
        int op = 0;
        for(int i=0;i < n/ 2; i++){ // target = (sum of values / n) = (n *n) / n
            op += (n - 2 * i - 1);
        }
        
        return op;
        
    }
};
