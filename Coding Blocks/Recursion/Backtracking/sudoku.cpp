/* To solve sudoku
 * 15-Jul-21 12:26:47 PM
*/
#include<iostream>
#include<cmath>
using namespace std;
// to check if we can place the current number in the cell i,j
bool canPlace(int mat[][9],int i,int j,int n, int number)
{
    // firsly check if the number is already present in the current row or column

    for(int x=0;x<n;x++){
        // row and column check
        if(mat[i][x]==number || mat[x][j]==number)
            return false;
    }
    
    int rn= sqrt(n); // root n
    
    // Now checking within the grid
    // sx,sy---> starting point of the grid
    int sx= (i/rn)*rn; 
    int sy= (j/rn) *rn; 
    
    for(int x=sx;x<(sx+rn);x++){
        for(int y=sy;y<(sy+rn);y++)
            if(mat[x][y]==number)
                return false;
    }
    
    return true;
}


void printmatrix(int mat[][9],int n);
// here i denotes the current row 
// j denotes the current coln
bool sudoku(int mat[][9],int i,int j,int n)
{
    // base case
    if(i==n){
        // Print the matrix
        printmatrix(mat,n);
        return true;
    }
    
    // Case Row End
    if(j==n){
        // go to the next row
       return sudoku(mat,i+1,0,n); 
    }

    // Skip the pre-filled cells
    
    if(mat[i][j]!=0){
        return sudoku(mat,i,j+1,n);
    }

    // Recursive case
    // Fill the current cell with possible options
    
    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){

            // assume for now that 'number' can be placed here
            mat[i][j]=number;

            bool assumption = sudoku(mat,i,j+1,n);

            if(assumption== true){
                return true;
            }
        }
    }

    // Backtracking
    mat[i][j]=0;

    return false;

}

int main()
{
    int matrix[9][9]={
        // 1 2 3 4 5 6 7 8 9
        {  0, 0, 0,  0, 0, 2,  0, 0, 0, },
        {  0, 8, 0,  6, 0, 0,  1, 0, 5, },       
        {  3, 0, 0,  5, 0, 4,  0, 0, 0, },
        {  0, 0, 1,  0, 0, 5,  3, 0, 0, },
        {  0, 6, 0,  0, 8, 0,  0, 9, 0, },      
        {  0, 0, 0,  3, 0, 0,  7, 0, 0, },
        {  0, 0, 4,  2, 0, 3,  0, 0, 9, },
        {  7, 0, 5,  0, 0, 6,  0, 0, 0, },       
        {  0, 0, 0,  9, 0, 0,  0 ,0 ,0  },

    };
    cout<<"SUDOKU\n";
    printmatrix(matrix,9);
    cout<<endl<<endl;
    cout<<"SOLUTION\n";
    sudoku(matrix,0,0,9);
    
    return 0;
}

// to print the matrix
void printmatrix(int mat[][9],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
            
            if(j==2 || j==5) cout<<" ";
        }
        cout<<endl;
        if(i==2 || i==5) cout<<endl;
    }
}
