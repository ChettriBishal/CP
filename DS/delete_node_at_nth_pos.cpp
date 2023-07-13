/*
 * To delete a node at nth position
 * In the insert function here the node is inserted at the end
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
node* head; // global variable
void Insert(int data); // to insert value at the end of the list
void Print();
void Delete(int n); // deletes node at position n
void Insert(int val) // inserting node at the end
{
    node* temp1=new node();
    temp1->data=val;
    temp1->next=NULL; // cause now this will the last node
    if(head==NULL) // inserting the first node
    {
        head=temp1;
        return;
    }
    node* temp2=head;
    while((temp2->next)!=NULL){// traversing till the last node
        temp2=temp2->next;
    }
    temp2->next=temp1; // last element
}
void Print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void Delete(int n)
{
    node* temp1=head;
    if(n==1){ // deleting the first node
        head=temp1->next; // head now points to the first node
        delete temp1;
        return;
    }
    for(int i=0;i<n-2;i++)
        temp1=temp1->next;
    //temp1 will point to the n-1th node
    node* temp2=temp1->next; // this points to the nth node ie the node we're deleting
    temp1->next=temp2->next; // breaking the link.. (n-1)th -->(n+1)th
    delete temp2; // actually freeing the memory
}
int main()
{
    head=NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2,4,6,5
    Print();
    int n;
    printf("\nEnter the position to delete: "); // assume the user enters a valid position
    cin>>n;
    Delete(n);
    Print();
}
