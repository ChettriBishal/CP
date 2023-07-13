#include<bits/stdc++.h>
using namespace std;
string convert(int a){ // convert to time based string 
    string s=to_string(a);
    if(s.length()==1) // like 2--->02
        s.insert(s.begin(),1,'0');
    return s;
}
int main(){
    int h,m;
    scanf("%d:%d",&h,&m);
    if(h==23){ //corner case
        if(m<32 and m!=32)
            printf("23:32\n");
        else{
            cout<<"00:00\n";
        }
    }
    else{ // first check  if the minute is less than (and not equal to reverse of hour)
        int a=h,b=(a%10)*10+(a/10);
        string h1,m1;
        h1=convert(a),m1=convert(b);
        if(b<60 and m<b and m!=b) // if yes
            cout<<h1<<":"<<m1<<endl;
        else{ // if no then print for the next hour whose reverse = minute<60
            do{
                h++;
                a=h,b=(a%10)*10+(a/10); // b is the reverse of a
            }while(b>=60);
            h1=convert(a),m1=convert(b);
            cout<<h1<<":"<<m1<<endl;
        }
    }
    return 0;

}
