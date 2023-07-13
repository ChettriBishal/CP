/* Using 2 D prefix sum 
 * Use 1 based indexing in prefix sum array
 * */
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int m = 4, n=5;
    int matrix[m+1][n+1]={
        {0,0,0,0,0,0},
        {0,1,2,3,4,5},
        {0,6,7,8,9,3},
        {0,3,8,2,1,0},
        {0,6,2,9,4,3}
    };

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int prefix[m+1][n+1]; // prefix sum array 2D
    memset(prefix,0,sizeof(prefix));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j] = matrix[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }


    cout<<"Enter the number of queries\n";
    int q; cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1]<<endl;

    }

    cout<<endl<<"Prefix SUM\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<prefix[i][j]<<" ";
        cout<<endl;
    }
}

