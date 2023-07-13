/*
 * Doubly linked list full implementation
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* prev,*next; // two pointers
};
node* head; // global.. pointer to head node
node* getnewnode(int x){   
    node* mynode=new node;
    mynode->data=x;
    mynode->next=NULL;
    mynode->prev=NULL;
    return mynode;
}
void Insert_at_head(int x) // to insert at the beginning of the list
{
    node* temp=getnewnode(x);
    if(head==NULL) // inserting the first node
    {   
        head=temp;
        return;
    }
    head->prev=temp; // setting back link for the previously first element  <--
    temp->next=head; // setting front link with the previously first element -->
    head=temp; // head is now the first element 
}
void Insert_at_tail(int x)
{
    node* temp1=getnewnode(x);
    if(head==NULL) // inserting the first node
    {
        head=temp1;
        return;
    }
    node* temp2=head;
    while(temp2->next!=NULL) // moving to the last element
        temp2=temp2->next;
    temp2->next=temp1; // creating link with the last
    temp1->prev=temp2; // back link with the the (past) last
}
void Delete(int n)
{
    if(head==NULL) return; // empty list
    node* temp=head; // temp will point to the node to be deleted
    if(n==1){   // if we're deleting the first node 
        head=temp->next;
        temp->next->prev=NULL; // second element's prev should be NULL
        delete temp;
        return;
    }
    for(int i=0;i<n-1;i++) // traverse to the node to be deleted--->current node=node to be deleted
        temp=temp->next;
    if(temp==NULL) return; // out of bounds
    if(temp->next==NULL) // if we're deleting the last node
    {   
        temp->prev->next=NULL; // second last node's next should be NULL
        delete temp;
        return;
    }// if the node to be deleted lies in between the first and last node
    // the node ahead of current one should be back-linked to the node before the current one
    temp->next->prev=temp->prev;
    // the node behind the current one should be linked to node after the current one
    temp->prev->next=temp->next;
    delete temp;
}
void Print()
{
    node* temp=head;
    cout<<"Forward: ";
    while(temp!=NULL)
    {   
        cout<<temp->data<<" ";
        temp=temp->next; // using next here
    }
    cout<<"\n";
}
void ReversePrint()
{
    node* temp=head;
    if(temp==NULL) return; // empty list
    while(temp->next!=NULL)
        temp=temp->next;
    cout<<"Reverse: ";
    while(temp!=NULL) // traversing backward using prev
    {
        cout<<temp->data<<" ";
        temp=temp->prev; // using prev here
    }
    cout<<"\n";
}
int main()
{   
    head=NULL;

    /*
    cout<<"On inserting at tail\n";
    Insert_at_tail(2); Print(); ReversePrint();
    Insert_at_tail(4); Print(); ReversePrint();
    Insert_at_tail(6); Print(); ReversePrint();
    */
    cout<<"Enter number of elements you want: ";
    int n;cin>>n;
    printf("Enter %d numbers to the node: ",n);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        Insert_at_tail(d);
    }
    Print();
    ReversePrint();
    bis:
    cout<<"How many elements do you want to delete: ";
    int m;cin>>m;
    if(m>=n){    
        cout<<"You can't delete all or more than you have: \n";
        goto bis;
    }
    for(int i=0;i<m;i++)
    {   
        cout<<"Enter position to delete: ";
        int d;
        cin>>d;
        Delete(d);
        Print();
    }
    /*
    cout<<"On inserting at head\n";
    Insert_at_head(2); Print(); ReversePrint();
    Insert_at_head(4); Print(); ReversePrint();
    Insert_at_head(6); Print(); ReversePrint();
    */
    return 0;
}
