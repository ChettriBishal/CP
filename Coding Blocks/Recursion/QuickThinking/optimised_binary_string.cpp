#include<iostream>
using namespace std;

void helper(char* s, int pos, int max_len)
{
    if(pos==max_len){
        s[pos]='\0';
        cout<<s<<endl;
        return ;
    }
    // 01 then we can't have 011 
    // thus we put 0...to get 010

	// if previous character is '1' then we put 
	// only 0 at end of string 
	//example str = "01" then new string be "010" 
    if(s[pos-1]=='1')
    {
        s[pos]='0';
        helper(s,pos+1,max_len);
    }
    // else we have two choices 
    // 001... or 000...

    // if previous character is '0' than we put 
	// both '1' and '0' at end of string 
	// example str = "00" then new string "001" and "000" 
    else{
        s[pos]='1';
        helper(s,pos+1,max_len);
        s[pos]='0';
        helper(s,pos+1,max_len);
    }
}

void all_possible(int max_len)
{
    if(max_len<=0)
        return ;
    char s[max_len];
    
    // Generate all substrings starting with '0'
    s[0]='0';
    helper(s,1,max_len);

    // Generate all substrings starting with '1'
    s[0]='1';
    helper(s,1,max_len);
}

int main()
{
    cout<<"Enter the max length of the string\n";
    int n;
    cin>>n;
    all_possible(n);

    return 0;

}

