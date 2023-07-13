#include<iostream>
using namespace std;

void generate_brackets(char* output,int N, int idx, int opening, int closing)
{
    // base case

    if(idx==2*N){
        output[idx]='\0';
        cout<<output<<endl;
        return;
    }

    // recursive case

    if(opening<N){
        output[idx]='(';
        generate_brackets(output,N,idx+1,opening+1, closing);
    }

    if(closing<opening){
        output[idx]=')';
        generate_brackets(output,N,idx+1,opening,closing+1);
    }

}

int main()
{
    cout<<"Enter N to generate N pairs of round brackets\n";
    int N;
    cin>>N;
    char output[2*N+1];
    int idx=0;
    generate_brackets(output,N,idx,0,0);
}
