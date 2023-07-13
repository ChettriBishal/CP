#include<iostream>
#include<cstring>
using namespace std;

void replacepi(char *a , int i)
{
    // base case
    if(a[i]=='\0' || a[i+1]=='\0'){
        return ;
    }

    // look for pi in the current position
    if(a[i]=='p' && a[i+1]=='i')
    {

        int j=i+2;

        while(a[j]!='\0') 
           j++; 
       
        // shifting characters to the right two steps 
        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }

        a[i]='3'; a[i+1]='.' ; a[i+2]='1'; a[i+3]='4';

        replacepi(a,i+4);
    }
    else{
        // go to next position
        replacepi(a,i+1);
    }
}

int main()
{
    char a[1000];
    cin>>a;

    replacepi(a,0);

    cout<<a<<endl;

    return 0;
}
