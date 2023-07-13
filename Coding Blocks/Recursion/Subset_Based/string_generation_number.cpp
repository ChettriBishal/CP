#include<iostream>
using namespace std;

void generate_strings(char* input,char* output, int i,int j)
{
    // base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    
    // recursive case: two options
    
    // 1. Pick one digit at a time
    int dig1 = input[i]-'0';

    char ch = dig1 + 'A'-1;

    output[j]=ch;
    generate_strings(input,output,i+1,j+1);

    // 2. Pick two digits at a time
    if(input[i+1]!='\0'){
        int dig2= input[i+1]-'0';
        int no= dig1*10+ dig2;
        
        if(no<=26){
            ch= no+'A'-1;
            output[j]= ch;
            generate_strings(input,output,i+2,j+1);
        }
    }
    return;
}
void alpha_number() // to display the alphanumeric values
{ 
    for(int i=1;i<=26;i++)
        cout<<i<<" "<< char(i+'A'-1)<<"| ";

    cout<<endl;
}

int main()
{
    alpha_number();
    cout<<"Enter a numeric string \n";
    char input[100], output[100];
    cin>>input;

    generate_strings(input,output,0,0);

    return 0;

}
