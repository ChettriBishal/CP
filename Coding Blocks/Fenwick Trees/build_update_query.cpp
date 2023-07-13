#include<iostream>

using namespace std;

int BIT[1000], a[1000];


void update(int i,int inc,int n)
{
    while(i<=n){
        BIT[i] += inc;
        i += (i & (-i));
    }
}

// sum of elements upto ith index
int query(int i)
{
    int res = 0;
    while(i>0){   // greater than 0 
        res += BIT[i];
        i -= (i & (-i));
    }
    return res;
}

void build(int n)
{
    for(int i= 1;i<=n;i++){
        update(i,a[i],n);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
        cin>>a[i];

    build(n);

    for(int i=1;i<=n;i++)
        cout<<BIT[i]<<" ";
    cout<<endl;
    // queries
    int q; 
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(r) - query(l-1)<<endl;
    }

    return 0;

}
