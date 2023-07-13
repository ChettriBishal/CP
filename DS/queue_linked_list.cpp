/* Queue Linked List Implementation */
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* front=NULL;
node* rear=NULL;
void Enqueue(int x) // to insert at rear
{
    node* temp=new node;
    temp->data=x;
    temp->next=NULL;
    if(front==NULL and rear==NULL) // first entry
    {
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void Dequeue() // to remove from front
{
    if(front==NULL){
        cout<<"Empty Queue\n";
        return;
    }
    node* temp=front;
    if(front==rear){
        front=rear=NULL;
    }
    else 
        front=front->next;
    delete temp;
}
void Print()
{
    cout<<"Queue: ";
    node* temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main()
{
    cout<<"Enter the size of the queue\n";
    int n; cin>>n;
    cout<<"Enter the elements in queue\n";
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        Enqueue(d);
    }
    Print();
    cout<<"How many deque operations do you want to do < "<<n<<endl;
    int t; cin>>t;
    while(t--){
        Dequeue();
        Print();
    }
    return 0;
}
