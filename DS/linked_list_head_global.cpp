/* To insert an element in the beginning of the list 
 * Using global declaration for head
 * head is the starting address of the list
 */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
struct node* head=NULL; // global declaration 
void Insert(int x)
{   
    node* temp= new node;
    temp->data=x;
    temp->next=head;
    head=temp;
}
void Print()
{
    node* temp=head;
    cout<<"The list is: ";
    while(temp!=NULL)
    {   
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){   
        cout<<"Enter a number: ";
        int d; cin>>d;
        Insert(d);
        Print();
    }
    return 0;
}
