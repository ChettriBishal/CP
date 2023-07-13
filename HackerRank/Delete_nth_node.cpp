#include <bits/stdc++.h>

using namespace std;

class node {
    public:
        int data;
        node *next;

        node(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};
node* insert(node* head, int data){
    node* temp= new node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    node *trav=head;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=temp;
    return head;
}
void __print(node* head){
    node* trav=head;
    while(trav!=NULL){
        cout<<trav->data<<" ";
        trav=trav->next;
    }
}
node* deln(node* head, int pos){
    node* temp=head;
    if(pos==1){
        head=head->next;
        delete temp;
        return head ;
    }
    for(int i=0;i<pos-2;i++){
        temp=temp->next;
    }
    // temp now points to n-1th node
    node* temp2=temp->next; // temp2 points to nth node
    temp->next=temp2->next; 
    delete temp2;
    return head;

}
int main()
{
    node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        head=insert(head,d);
    }
    __print(head);
    cout<<"\nEnter a postion to delete: ";
    int pos;
    cin>>pos;
    head=deln(head,pos);
    __print(head);
    return 0;
}

