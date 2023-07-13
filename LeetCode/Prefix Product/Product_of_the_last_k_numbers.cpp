class ProductOfNumbers {
public:
    vector<int> pre;
    ProductOfNumbers() {
       pre = {1}; 
    }
    
    void add(int num) {
       if(num == 0){
           pre.clear();
           pre = {1};
       } 
        else
            pre.push_back(pre.back() * num);
    }
    
    int getProduct(int k) {
        if(k >= pre.size())
           return 0;
        return pre.back() /pre[pre.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
