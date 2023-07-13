/*Queue Cirular Array implementation */
#include<iostream>
using namespace std;
#define n 101 // max size of the circular queue
class Queue
{
    private:
        int a[n];
        int front,rear;
    public:
        //constructor to initiate an empty queue 
        // for an empty queue both front and rear are -1
        Queue(){
            front=-1;
            rear=-1;
        }


        bool IsEmpty() // to check if the queue is empty or not
        {
            return (front==-1 and rear==-1);
        }
        
        bool IsFull() // to check if the queue is full
        {
            return (rear+1)%n==front?true:false;
        }

        void Enqueue(int x) // to insert element at rear
        {
            cout<<"Enqueuing "<<x<<"\n";
            if(IsFull()){
                cout<<"Error: Queue is full\n";
                return;
            }
            if(IsEmpty())
                front=rear=0; 
            else
                rear=(rear+1)%n;
            a[rear]=x;
        }

        void Dequeue() // to remove element from the front
        {
            cout<<"Dequeuing\n";
            if(IsEmpty()){
                cout<<"Error: Queue is empty\n";
                return;
            }
            else if(front==rear) // only one element
                front=rear=-1;
            else
                front=(front+1)%n;
        }
        
        int Front()  // returns the front element (head)
        {
            if(front==-1){
                cout<<"Error: Cannot return front from an empty queue\n";
                return -1; // no element
            }
            return a[front];
        }

        void Print() // to print the elements in circular queue
        {
            int count=(rear+n-front)%n+1; // no of elements present in the queue
            cout<<"Queue: ";
            for(int i=0;i<count;i++)
            {
                int ind=(front+i)%n; // index of the element while traversing circularly from front
                cout<<a[ind]<<" ";
            }
            cout<<"\n";
        }
};

int main()
{
    Queue q; // creating an instance of Queue
    
    q.Enqueue(2); q.Print();
    q.Enqueue(4); q.Print();
    q.Enqueue(6); q.Print();
    q.Dequeue(); q.Print();
    q.Enqueue(8); q.Print();
    q.Enqueue(9); q.Print();
    q.Enqueue(11); q.Print();
    q.Dequeue(); q.Print();

    return 0;
}
