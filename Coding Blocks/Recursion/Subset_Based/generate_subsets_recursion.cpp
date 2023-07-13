#include<iostream>
using namespace std;

void generate_subsets(char* input, char* output, int i, int j)
{
    // base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return ;
    }
    
    // recursive case

    // 1. Include the current character

    output[j]=input[i];  // copying that into output array

    generate_subsets(input,output,i+1,j+1);

    // 2. Exclude the current character

    // don't update the value of j
    
    generate_subsets(input,output,i+1,j);

}


int main()
{
    cout<<"Enter a string to find it's subsequences\n";

    char input[20]; // to store the input string

    char output[21]; // to store the output string
    cin>>input;

    generate_subsets(input, output, 0,0);

    return 0;
}
