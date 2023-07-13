/* To find the maximum and minimum element in a BST */
#include<iostream>
using namespace std;
struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};
BSTNode* newNode(int data){
    BSTNode* temp= new BSTNode;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
BSTNode* Insert(BSTNode* root, int data)
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
int FindMax(BSTNode* root){
    if(root==NULL){
        cout<<"ERROR Tree is empty\n";
        return -1;
    }
    BSTNode* trav=root;
    while(trav->right!=NULL){
        trav=trav->right;
    }
    return trav->data;
}
int FindMin(BSTNode* root){
    if(root==NULL){
        cout<<"ERROR Tree is empty\n";
        return -1;
    }
    BSTNode* trav=root; // else we can directly use root as it's a local copy
    while(trav->left!=NULL)
        trav=trav->left;
    return trav->data;
}
int FindMin2(BSTNode* root); // recursive
int FindMax2(BSTNode* root); //recursive
int main()
{
    freopen("input.txt","r",stdin);
    cout<<"Enter the number of elements you want to enter in the binary tree\n";
    int n;
    cin>>n;
    printf("Enter %d values: \n",n);
    BSTNode* root=NULL;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        root=Insert(root,d);
    }
    printf("Maximum element in the tree is: %d\n",FindMax(root));
    printf("Minimum element in the tree is: %d\n",FindMin(root));
    cout<<"\nUsing recursive functions\n";
    printf("Maximum element in the tree is: %d\n",FindMax2(root));
    printf("Minimum element in the tree is: %d\n",FindMin2(root));
    return 0;
}
int FindMin2(BSTNode* root)
{
    if(root==NULL)
    {
        cout<<"ERROR Tree is empty\n";
        return -1;
    }
    if(root->left==NULL)
        return root->data;
    else
        return FindMin2(root->left);
}
int FindMax2(BSTNode* root)
{
    if(root==NULL)
    {
        cout<<"ERROR Tree is empty\n";
        return -1;
    }
    if(root->right==NULL)
        return root->data;
    else
        return FindMax2(root->right);
}
