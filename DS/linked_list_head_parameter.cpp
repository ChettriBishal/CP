/* To insert an element in the beginning of the list 
 * We pass head as a parameter into Print and Insert
 * */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
node* Insert(node* head,int x)
{   
    node* temp= new node;
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}
void Print(node* head)
{ // head will be a local variable for this function
    cout<<"The list is: ";
    while(head!=NULL)
    {   
        cout<<head->data<<" ";
        head=head->next;
    }
    printf("\n");
}
int main()
{
    node* head=NULL; // local declaration in main
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){   
        cout<<"Enter a number: ";
        int d; cin>>d;
        head=Insert(head,d);// after going into the Insert() head will be modified 
        Print(head);
    }
    return 0;
}
