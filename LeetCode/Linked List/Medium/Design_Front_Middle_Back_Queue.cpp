/*
Make sure a.size() be either b.size() or b.size() - 1 so that when we pushMiddle, always push to a.

a2b and b2a are two helper functions nudging numbers around to ensure the above criteria.
*/

class FrontMiddleBackQueue {
public:
    deque<int> a,b;
    void a2b(){
        if(a.size() <= b.size())
            return;
        b.push_front(a.back());
        a.pop_back();
    }
    void b2a(){
        if(b.size() -1 <= a.size())
            return;
        a.push_back(b.front());
        b.pop_front();
    }
    
    FrontMiddleBackQueue(){ }
    
    void pushFront(int val) {
        a.push_front(val);
        a2b();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    
    int popFront() {
        if(a.empty() && b.empty())
            return -1;
        int el;
        if(a.empty()){
            el = b.front();
            b.pop_front();
        }
        else{
            el = a.front();
            a.pop_front();
            b2a();
        }
        return el;
    }
    
    int popMiddle() {
        if(a.empty() && b.empty())
            return -1;
        int el;
        if(a.size() == b.size()){
            el = a.back();
            a.pop_back();
            b2a();
        }
        else{
            el = b.front();
            b.pop_front();
            a2b();
        }
        return el;
    }
    
    int popBack() {
        if(a.empty() && b.empty())
            return -1;
        int el = b.back();
        b.pop_back();
        a2b();
        return el;
    }
};

/*

Input:
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
Output:
[null, null, null, null, null, 1, 3, 4, 2, -1]

Explanation:
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)

*/
