class CustomStack {
public:
    // lazy increment 
    vector<int> arrStack, inc;
    int N;
    CustomStack(int maxSize) {
        N = maxSize;
    }
    
    void push(int x) {
        if(arrStack.size() == N)
            return;
        arrStack.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int i = arrStack.size()-1; // last element
        if(i < 0)
            return -1;
        if(i > 0)
            inc[i-1] += inc[i];
        
        int res = arrStack[i] + inc[i];
        
        arrStack.pop_back();
        inc.pop_back();
        
        return res;        
    }

    void increment(int k, int val) {
        int i = min((int)arrStack.size(), k) -1;
        
        if(i >= 0)
            inc[i] += val;
    }
};
