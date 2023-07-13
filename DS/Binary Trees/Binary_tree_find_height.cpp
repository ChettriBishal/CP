/* to calculate the height of a binary tree */
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newNode(int data){
    node * temp=new node;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
node * Insert(node* root,int data)
{
    if(root==NULL){
        root=newNode(data);
    }
    else if(root->data<data){
        root->right=Insert(root->right,data);
    }
    else
        root->left=Insert(root->left,data);
    
    return root;
}
// function to find height
int Findh(node* root){
    if(root==NULL){ // empty node has no edges downwards 
        return -1 ; // height of an empty tree is -1
    }
    int lh=Findh(root->left); // height of left subtree 
    int rh=Findh(root->right); // height of right subtree
    return max(lh,rh)+1;
}
int main()
{  
    freopen("input.txt","r",stdin);
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    node* root=NULL;
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        cout<<d<<endl;
        root=Insert(root,d);
        if(root->left!=NULL){
            cout<<"left: ";
            cout<<root->left->data<<" ";    
        }
        if(root->right!=NULL){
            cout<<"right: ";
            cout<<root->right->data<<" ";
        }
        cout<<"\n";
    }
    cout<<"Height of the binary tree: "<<Findh(root)<<"\n";
    return 0;

}
/*
 * Consider this input
 * 9
 * 1 2 3 4 5 6 7 8 9
 * Height= 8 (unbalanced) -->observe the sequence in which you enter
 *
 * Now consider this
 * 9
 * 8 4 3 6 5 7 10 9 11
 * Height = 3 (balanced)
 */
