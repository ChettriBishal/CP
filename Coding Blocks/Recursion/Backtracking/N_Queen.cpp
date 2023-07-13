#include<iostream>
using namespace std;

// to check if the current cell is safe or not
bool issafe(int a[][10],int i,int j,int n)
{
    // check the current column

    for(int row=0;row<i;row++)
        if(a[row][j]==1)
            return false;

    // check the left diagonal
    int x=i, y=j;
            
    while(x>=0 && y>=0){
        if(a[x][y]==1)
            return false;
        x--,y--;
    }
    
    // now check the right diagonal
    x=i,y=j;

    while(x>=0 && y<n){
        if(a[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;

}

bool Nthqueen(int a[][10],int row,int n)
{
    // base case

    if(row==n)
    {
        // print the matrix
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1)
                    cout<<" Q";
                else
                    cout<<" _";
            }
            cout<<endl<<endl;
        }
        return false;     // To print all the possible solutions

        // return true to print only the first one  
    }

    for(int i=0;i<n;i++)
    {
        // assuming the current cell to be correct one
        
        bool check= issafe(a,row,i,n);

        if(check){

            a[row][i]=1;
            bool nextqueen= Nthqueen(a,row+1,n);
            
            if(nextqueen){
                return true;
            }
            
            // if control reaches here...means that our assumption is wrong
            a[row][i]=0; // backtracking
        }
    }

    return false;
}

int main()
{
    cout<<"Enter the value of N for the matrix\n";
    int n;
    cin>>n;

    int a[10][10]={0};
    Nthqueen(a,0,n);

    return 0;
}




