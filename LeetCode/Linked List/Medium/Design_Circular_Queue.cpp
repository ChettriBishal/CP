class MyCircularQueue {
public:
    // we insert from rear 
    // and delete from front 
    vector<int> cq;
    int front, rear;
    int N; // max size of circular queue 
    MyCircularQueue(int k) {
        front = rear = -1;
        cq.resize(k,0);
        N = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty()){ // first entry
            front = rear = 0;
            cq[0] = value;
            return true;
        }
        
        rear = (rear + 1) % N;
        cq[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(rear == -1 && front == -1)
            return false;
        if(rear == front){ // only one value 
            rear = front = -1;
            return true;
        }
        front = (front + 1) % N; // moving front forward 
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return cq[front];
        
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return cq[rear];
    }
    
    bool isEmpty() {
        if(rear == -1 && front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((rear + 1) % N == front)
            return true;
        return false;
    }
};
