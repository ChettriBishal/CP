#include<bits/stdc++.h>
using namespace std;
vector<string> keypad{" ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void generate(string s,string res,int i)
{
    if(i==(int)s.length()){
        cout<<res<<endl;
        return;
    }
    int dig= s[i]-'0'; 
    
    for(auto k:keypad[dig]){
        generate(s,res+k,i+1);
    }
    
}
int main()
{
    string s;
    cin>>s;
    string res="";
    generate(s,res,0);

    return 0;
}
