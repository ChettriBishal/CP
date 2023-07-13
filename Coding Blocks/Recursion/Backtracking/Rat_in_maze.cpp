#include<iostream>
using namespace std;

// this function will have the following parameters
// the maze, the soln matrix, current coordinates, destination coordinates

bool rat_in_Maze(char maze[10][10],int soln[][10], int i,int j, int m, int n,int& cnt)
{
    // base case
    if(i==m && j==n){
        soln[m][n]=1;
       
        cnt++; // increment the number of paths
        
        // print the path
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
                cout<<soln[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    // rat should be inside the grid
    if(i>m || j>n){
        return false;
    }

    if(maze[i][j]=='X'){
        return false;
    }

    // assume solution exists through current cell
    soln[i][j]=1;
    
    bool rightside = rat_in_Maze(maze, soln,i,j+1,m,n,cnt);
    bool downside = rat_in_Maze(maze, soln,i+1,j,m,n,cnt);

    // backtracking
    soln[i][j]=0;

    if(rightside || downside){
        return true;
    }
    return false;

}

int main()
{
    char maze[10][10]= {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10]={0};
    
    int m=4,n=4;
    int cnt=0; // to count the number of paths that are possible  
    bool ans = rat_in_Maze(maze,soln,0,0,m-1,n-1,cnt);
    
    if(ans== false)
        cout<<"Path does not exist\n";
    else
        cout<<cnt<<" path(s) exist\n";

    return 0;
}
