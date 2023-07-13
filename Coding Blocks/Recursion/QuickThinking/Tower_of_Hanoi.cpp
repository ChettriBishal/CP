#include<iostream>
using namespace std;

void move(int n, char src, char helper, char dest)
{
    if(n==0)
        return ;
    // move n-1 disks from source to helper 
    
    // Recursive case has three steps 
    
  /* 1st step */  move(n-1, src, dest,helper);
    
  /* 2nd step */  cout<<"Shift disk "<<n<<" from "<<src<<" to "<<dest<<endl;

  /* 3rd step */  move(n-1,helper,src,dest);
}
int main()
{
    // Enter the number of disks in A
    int n;
    cin>>n;
    move(n,'A','B','C');

    return 0;
}
