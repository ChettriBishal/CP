#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> bis;

void codes(string in, int s,string res)
{
    if(s == (int) in.length()){
        bis.push_back(res);
        return ;
    }
    //char ch = in [s]-'0' + 'a' -1 ;

    char ch = in [s]-'0' + 96 ;
    codes(in,s+1,res+ch);

    // generate two strings at a time
    if(s+1 != (int) in.length()){
        int dig2 = in[s+1] - '0';
        int dig1 = in[s] - '0';
        int num = dig1*10 + dig2;
        if(num <=26){
            //ch = num + 'a'-1;
            ch = num + 96;
            codes(in,s+2,res+ch);
        }
        return ;
    }
    return ;
}

void display()
{
    cout<<"[";
    int n = bis.size();
    for(int i= 0;i<n;i++){
        cout<<bis[i];
        if(i<n-1) cout<<", ";
    }
    cout<<"]"<<endl;

}
int main()
{
    string in,res="";
    cin>>in;
    
    codes(in,0,res);
    
    display();

    return 0;
}
