// range update 
#include<iostream>
using namespace std;

void buildTree(int* a,int s, int e,int* tree, int index)
{
    // base case
    if(s==e){
        tree[index]= a[s];
        return;
    }

    // Recursive case

    int mid = (s+e)/2;
   
    // left subtree
    buildTree(a,s,mid,tree,2*index); 

    // right subtree
    buildTree(a,mid+1,e,tree,2*index+1);

    // current root node
    tree[index] = min(tree[2*index],tree[2*index + 1]); 

    return;


}

int query(int * tree, int ss, int se,int qs,int qe,int index)
{
    // First check for Complete overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }

    // No overlap
    if(qe<ss || qs>se){
        return INT_MAX;
    }

    // Partial overlap
    int mid = (ss+se)/2;
    int left = query (tree,ss,mid,qs,qe,2*index);
    int right = query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);
}

void updateRange(int* tree, int ss,int se,int l,int r,int inc,int index)
{
    // check if 'in' is out of bounds
    if(l>se || r<ss){
        return;
    }
    
    // leaf node
    if(ss==se){
        tree[index]+=inc;
    }

    // recursive case
    int mid = (ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);

    tree[index]+= min(tree[2*index],tree[2*index+1]);
}

int main()
{
    int a[]={1,3,2,-5,6,4};

    int n = sizeof(a)/sizeof(int);

    int *tree = new int[4*n+1];

    buildTree(a,0,n-1,tree,1);

    // lets print the tree array
    for(int i=1;i<=13;i++){
        cout<<tree[i]<< " ";
    } cout<<endl;
    

    updateRange(tree,0,n-1,3,5,+10,1);

    for(int i=1;i<=13;i++){
        cout<<tree[i]<< " ";
    } cout<<endl;

    // Queries
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        
        cout<<query(tree,0,n-1,l,r,1)<<endl;
    }
    return 0;
}
