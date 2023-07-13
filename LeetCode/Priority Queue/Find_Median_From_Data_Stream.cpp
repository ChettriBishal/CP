class MedianFinder {
    public:
    priority_queue<int> maxh; // to store the left side of the array
    priority_queue<int,vector<int>, greater<int>> minh; // to store the right side of the array
    MedianFinder() {

    }

    void addNum(int num) {
        if(maxh.empty()){
            maxh.push(num);
        } 
        else if(num > maxh.top()){
            minh.push(num);
        }
        else{
            maxh.push(num);
        }
        // rearrange from minh
        if(minh.size() > maxh.size()){ // maxh should contain one extra element
            maxh.push(minh.top());
            minh.pop();
        }
        // rearrange from maxh
        if(maxh.size() - minh.size() >1){ 
            minh.push(maxh.top());
            maxh.pop();
        }

    }

    double findMedian() {
        if(maxh.size() > minh.size()){
            return maxh.top();
        } 
        double val = (double) maxh.top() + (double) minh.top();
        val /= 2.0;
        return val;
    }
};
