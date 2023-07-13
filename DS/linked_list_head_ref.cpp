/* To insert an element in the beginning of the list 
 * here we do not declare head globally hence we need to pass it every time we invoke the funtions
 * We pass head by reference into Insert()
 *
 * */
#include<iostream>
using namespace std;
struct node{    
    int data;
    node* next;
};
void Insert(node** head, int x) // notice the double ** for argument of type pointer to pointer 
{  // passing address of pointer of type node here  
// to use head we need to dereference it hence the * in front
    node* temp= new node;
    temp->data=x;
    temp->next=*head;
    *head=temp;
}
void Print(node* head)  
{    
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
        Insert(&head,d); // notice we're passing address of head // passing by reference 
        Print(head);
    }
    return 0;
}
