/* 
 *  14-May-21 6:20:19 PM
 *  Binary Search Tree Implementation 
 *  Insertion and searching in two ways:
 *  1. Recursion (Intuitive)
 *  2. Iterative
 *
 *  This doesn't include traversal
*/
#include<iostream> 
using namespace std;
struct BSTNode{
    int data;
    BSTNode* left; // to store the address of left child
    BSTNode* right; // to store the address of right child
};
BSTNode* GetNewNode(int data){ // to get a new node
    BSTNode* node=new BSTNode;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
BSTNode* Insert(BSTNode* root, int data)
{
    if(root==NULL) // if tree is empty
    {
        root=GetNewNode(data);
    }
    else if(data<=root->data){       // insert in left subtree
        root->left= Insert(root->left,data);   // inserts and builds the link as well 
    }
    else{                 // insert in right subtree
        root->right= Insert(root->right,data);
    }

    return root;
}
void Insert2(BSTNode** root, int data);
bool Search(BSTNode* root,int data) // to check if a value is present in the tree
{
    if(root==NULL)
        return false;
    if(root->data==data)
        return true;
    if(root->data<data)  // search in the rigth subtree 
        return Search(root->right,data);
    else                // else search in the left subtree
        return Search(root->left,data);
}
bool Search2(BSTNode** root,int data);
int main()
{
    BSTNode *root=NULL; // Creating an empty tree
    
    // Inserting using recursive function  
    root= Insert(root,15); root= Insert(root,10);
    root= Insert(root,20); root= Insert(root,25);
    root= Insert(root,8); root= Insert(root,12);

    // Inserting using iterative function
    Insert2(& root, 38); Insert2(& root,67); Insert2(& root,89);
    Insert2(& root,49); Insert2(& root,54); Insert2(& root,99);
    int key;
    cout<<"Enter a number to search\n";
    cin>>key;
    if(Search(root,key)==true)
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    // Searching iteratively
    cout<<"Enter another number to search\n";
    cin>>key;
    if(Search2(& root,key)==true)
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    return 0;

}
void Insert2(BSTNode** root,int data) // to insert without recursion # iterative
{
    if(*root==NULL){ // first insertion
        *root=GetNewNode(data);
        return;
    }
    BSTNode* trav=*root; // to traverse the nodes and occupy approriate position
    BSTNode* parent=NULL; // parent node for subsequent subtrees during traversal
    while(trav!=NULL)
    {
        parent=trav;
        if(trav->data<data) // value is bigger than the current node value
            trav=trav->right;
        else
            trav=trav->left;
    }
    if(parent->data<data)
        parent->right=GetNewNode(data);
    else
        parent->left=GetNewNode(data);
}

bool Search2(BSTNode** root,int data) // to search iteratively
{
    BSTNode* trav= *root;
    if(data==(*root)->data)
        return true;
    while(trav!=NULL && trav->data!=data)
    {
        if(trav->data<data) // value is bigger than the current node value
            trav=trav->right;
        else
            trav=trav->left;
    }
    if(trav==NULL)
        return false;
    return true;
}
