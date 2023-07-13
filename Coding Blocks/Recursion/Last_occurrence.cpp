 /*
  *To find the last occurence of an element in the array
  */

#include<iostream>
using namespace std;
int locc(int* a,int key, int n)
{
    // first make and then look at the current index
    if(n==0)
        return -1;
   
    int check=locc(a+1,key,n-1);
   
    if(check==-1){
        if(a[0]==key) // check if the current one is the key 
            return 0;
        else
            return -1;
    }
    
    // if i returned is not -1 
    
    return check+1;

}

int main()
{
    int a[]={22,34,43,89,66,89,90};
    int n=sizeof(a)/sizeof(int);
    int key=89; 
    int there= locc(a,key,n);
    cout<<there<<endl;

    return 0;
}
