#include<iostream>
using namespace std;

void permute(char* input,int i)
{
    // base case

    if(input[i]=='\0'){
        cout<<input<<" ";
        return;
    }

    // recursive case

    for(int j=i;input[j]!='\0';j++)
    {
        swap(input[i],input[j]);
        permute(input,i+1);
        
        // backtracking
        swap(input[i],input[j]); // restoring the changes
    }
}


int main()
{
    char input[100];
    cout<<"Enter a string to generate all permutations\n";
    cin>>input;

    permute(input,0);

    return 0;
}
