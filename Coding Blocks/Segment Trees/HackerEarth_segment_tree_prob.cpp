#include<iostream>
#include<climits>
using namespace std;

void construct(int* a,int* tree,int s, int e,int ind)
{
    if(s==e){
        tree[ind] = a[s];
        return ;
    }
    int mid = (s+e)/2;

    construct(a,tree,s,mid,2*ind);
    construct(a,tree,mid+1,e,2*ind+1);

    tree[ind] = min ( tree[2*ind],tree[2*ind+1] );

    return ;
}
int query(int* tree,int s,int e,int qs,int qe,int ind)
{
    if(qs<= s && qe >=e){
        return tree[ind];
    }

    if(qe<s || qs >e){
        return INT_MAX;
    }
    
    int mid = (s+e) /2;
    
    int left = query(tree,s,mid,qs,qe,2*ind);
    int right = query(tree,mid+1,e,qs,qe,2*ind+1);

    return min(left,right);
}

void update(int* tree,int* a,int s,int e,int i,int val,int ind)
{
    if( i> e || i<s ) return;

    if(s==e){
        tree[ind] = val;
        a[i] = val;
        return;
    }

    int mid = (s+e)/2;
    update(tree,a,s,mid,i,val,2*ind);
    update(tree,a,mid+1,e,i,val,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n+1];
   
    for(int i=1;i<=n;i++)
        cin>>a[i];

    int tree[4*n+3];
    construct(a,tree,1,n,1); // to construct the tree

    // queries
    while(q--){
        char gb;
        int x,y;
        cin>>gb>>x>>y;
        if(gb=='q'){
            cout<<query(tree,1,n,x,y,1)<<endl;
        }
        else if(gb=='u'){
            update(tree,a,1,n,x,y,1);
        }
    }
    return 0;
}
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
