#include<iostream>
#include<vector>
using namespace std;

vector<string> words{"zero","one","two","three","four","five","six","seven","eight","nine","ten"};

void printwords(int n)
{
    // base case
    if(n==0)
        return;
    
    // recursive case 
    // first print the left most digits 
    printwords(n/10);

    int dig = n%10; // digit 
    cout<<words[dig]<<" ";
}

int main()
{
    cout<<"Enter a number to print as words\n";
    int num;
    cin>>num;
    printwords(num);

    return 0;
}
