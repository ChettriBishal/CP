/*
 * To insert node at a given position 
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
struct node* head;
void Insert(int val,int n)
{
    node* temp1=new node;
    temp1->data=val;
    temp1->next=NULL;
    if(n==1) // if we're inserting the first element
    {   
        temp1->next=head;
        head=temp1;
        return;
    }
    node* temp2=head;
    for(int i=0;i<n-2;i++){ // traversing till we reach the n-1th position
        temp2=temp2->next;
    } // after the traversal temp2 points to n-1th position
    temp1->next=temp2->next; // setting the link to the newly created node
    temp2->next=temp1;
}
void Print()
{
    node* temp=head;
    while(temp!=NULL)
    {   
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    head=NULL; // empty list
    Insert(2,1); // List: 2
    Insert(3,2); // List: 2 3
    Insert(4,1); // List: 4 2 3 
    Insert(5,2); // List: 4 5 2 3
    Print();
}
