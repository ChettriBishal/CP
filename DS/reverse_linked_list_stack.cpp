#include<iostream>
#include<stack>
using namespace std;
struct node{ 
    int data;
    node* next;
};
node* head=NULL;
void Insert(int x) // insert at the head
{
    node* temp=new node;
    temp->data=x;
    temp->next=head;
    head=temp;
}
void Print()
{
    node *temp=head;
    cout<<"List: ";
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void Reverse()
{
    stack<node*>s;  // to store the address
    node* temp=head;
    while(temp!=NULL) // to push all references in the stack
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=s.top(); // changing the head to point to the last element 
    head=temp;
    s.pop();
    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL; // first element should now point to NULL
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the list: ";
    cin>>n;
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        int d;cin>>d;
        Insert(d);
    }
    Print();
    cout<<"Reversed: ";
    Reverse();
    Print();
    return 0;

}
