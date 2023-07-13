#include<iostream>
using namespace std;

//                 0   1   2     3     4     5     6     7      8      9
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

// here i--> index of input array
// j--> index of output array

void generate_names(char* input, char* output,int i,int j)
{
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    // recursive case

    int digit = input[i]-'0';
    
    if(digit==1 || digit==0)  // as 1 and 0 is mapped to empty ""
    {
        generate_names(input,output,i+1,j);
    }
    for(int x=0; keypad[digit][x]!='\0';x++)
    {
        output[j] = keypad[digit][x];
        // fill the remaining part by making a recursive call

        generate_names(input,output,i+1,j+1);
    }

    return ;

}

int main()
{
    for(int i=0;i<10;i++){
        for(int j=0;keypad[i][j]!='\0';j++){
            cout<<keypad[i][j];
        }
        cout<<" ";
    }
    cout<<"\nEnter a numeric string to generate all suggestions\n";

    char input[100];
    cin>>input;


    char output[100];
    generate_names(input,output,0,0);
    
    return 0;
}
