#include<iostream>
#include<climits>
using namespace std;

void buildtree(int* tree,int* a, int s, int e,int index)
{
    if(s==e){
        tree[index] = a[s];
        return;
    }
    int mid = (s+e)/2;
    buildtree(tree,a,s,mid,2*index); 
    buildtree(tree,a,mid+1,e,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

void pointupdate(int* tree,int* a,int s,int e,int x,int val,int index)
{
    // if index is too low or too high
    if(x< s || x>e){
        return;
    }

    if(s == e){
        tree[index] = val;
        a[x] = val;
        return;
    }

    int mid = (s+e)/2;
    pointupdate(tree,a,s,mid,x,val,2*index);
    pointupdate(tree,a,mid+1,e,x,val,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int minquery(int* tree,int s,int e, int l,int r,int index)
{
    
    if(l<=s && r>=e){
        return tree[index];
    }

    if(r<s || l>e) 
        return INT_MAX;
    
    int mid = (s+e)/2;
    int left = minquery(tree,s,mid,l,r,2*index);
    int right = minquery(tree,mid+1,e,l,r,2*index+1);

    return min(left,right);
}

int main()
{
#ifdef Bis
    freopen("test.txt","r",stdin);
#endif
    int n,q;
    cin>>n>>q;
    int a[n+1];

    for(int i=1;i<=n;i++) 
        cin>>a[i];

    int tree[4*n+3];
    buildtree(tree,a,1,n,1);    
    
    while(q--){
        int c,lx,ry;
        cin>>c>>lx>>ry;

        if(c==1){
            cout<<minquery(tree,1,n,lx,ry,1)<<endl;
        }
        else{
            pointupdate(tree,a,1,n,lx,ry,1);
        }
    }

    return 0;
}
