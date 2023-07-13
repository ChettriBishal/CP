/*
 * To reverse a linked list 
 * Iterative implementation
 * Double pointers cause we pass head by reference 
 * So while using head we first dereference it *head 
 * The function parameter in Insert() and Reverse() receives pointer to head and not head itself
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
void Insert(node** head, int val) // inserting at the end of the list
{
    node* temp1=new node;
    temp1->data=val;
    temp1->next=NULL;
    if(*head==NULL){// inserting the first element  
        *head=temp1;
        return;
    }
    node* temp2=*head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    temp2->next=temp1;
}
void Print(node* head)
{
    node* temp=head;
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void Reverse(node** head)
{
    node *cur,*next,*prev;
    cur=*head;
    prev=NULL;
    while(cur!=NULL){   
        next=cur->next; // so that this value is not lost while breaking the link
        cur->next=prev; // reversing the link
        prev=cur;   // resetting for another round of execution
        cur=next; 
    }
    *head=prev; // at the end the last element now becomes the head
}
int main()
{
    node* head=NULL; // local declaration
    cout<<"Enter 5 numbers into the linked list\n";
    for(int i=0;i<5;i++){   
        int d;
        cin>>d;
        Insert(&head,d); // passing head by reference
    }
    cout<<"List: ";
    Print(head);
    cout<<"\n";
    Reverse(&head);
    cout<<"R List: ";
    Print(head);
    cout<<"\n";
    return 0;
}
