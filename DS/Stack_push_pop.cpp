/* to push and pop in a stack */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* link;
};
node* top=NULL;
void Push(int x) // insertion only from one end
{   
    node* temp=new node;
    temp->data=x;
    temp->link=top;
    top=temp;
}
void Pop()
{
    if(top!=NULL){ // only if the list is non empty
        node* temp=top;
        top=top->link; // break the link
        delete temp;
    }
}
void Print()
{
    node* temp=top;
    cout<<"Stack: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<"\n";
}
int main()
{
    cout<<"Enter the number of elements to enter in stack\n";
    int n; cin>>n;
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {   
        int d; cin>>d;
        Push(d);
        Print();
    }
    return 0;
}
