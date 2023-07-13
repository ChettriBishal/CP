/*
 * To reverse a linked list 
 * Recursive implementation
 * Global head used here
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
node* head; // global declaration
void Insert(int val) // inserting at the beginning of the list
{
    node* temp1=new node;
    temp1->data=val;
    temp1->next=NULL;
    if(head==NULL){ 
        head=temp1;
        return;
    }
    node* temp2=head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    temp2->next=temp1;
}


void Print()
{
    node* temp=head;
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}



void Reverse(node* temp) 
{
    if(temp->next==NULL){ // last node becomes the head node now  
        head=temp;
        return;
    }
    Reverse(temp->next); // Recursive call
    node* front=temp->next;
    front->next=temp; // the element ahead of the current one should point to the current one
    temp->next=NULL;
}

int main()
{
    head=NULL;
    cout<<"Enter 5 numbers into the linked list\n";
    for(int i=0;i<5;i++){   
        int d;
        cin>>d;
        Insert(d);
    }
    cout<<"List: ";
    Print();
    cout<<"\n";
    Reverse(head);
    cout<<"Reversed List: ";
    Print();
    cout<<"\n";
    return 0;
}


/*
void Reverse() // iterative implementation for reference 
{
    node *cur,*next,*prev;
    cur=head;
    prev=NULL;
    while(cur!=NULL){   
        next=cur->next; // so that this value is not lost while breaking the link
        cur->next=prev; // reversing the link
        prev=cur;   // resetting for another round of execution
        cur=next; 
    }
    head=prev; // at the end the last element now becomes the head
}
*/

