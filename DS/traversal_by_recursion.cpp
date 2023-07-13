/*
 * To print elements by recursion
 * forward and backward
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
node* Insert(node* head, int val) // inserting at the end of the list
{
    node* temp1=new node;
    temp1->data=val;
    temp1->next=NULL;
    if(head==NULL){ 
        head=temp1;
        return head;
    }
    node* temp2=head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    temp2->next=temp1;
    return head;
}
void Print(node* temp)
{
    if(temp==NULL)// when we reach the end of the list
        return;
    cout<<temp->data<<" "; // first print the value in the node
    Print(temp->next);  //Recursive call
}
void ReversePrint(node* temp)
{
    if(temp==NULL) return;
    ReversePrint(temp->next);
    cout<<temp->data<<" ";
}
int main()
{
    node* head=NULL;
    head=Insert(head,2);
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,5);
    cout<<"List: ";
    Print(head);
    cout<<"\n";
    cout<<"List in reverse: ";
    ReversePrint(head);
    cout<<"\n";
    return 0;
}
