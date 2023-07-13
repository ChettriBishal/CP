#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char s[100]="Lets get red soon"; // string
    char *token=strtok(s," "); // break string s about spaces
    while(token) // while token is not NULL
    {
        cout<<token<<endl;
        token=strtok(NULL," ");
    }
    return 0;

}
/*
 * char * strtok(char *s, char * delimeters)
 * returns token on each subsequent call
 * on the first call function should be passed with string argument for s
 * on the subsequent calls we should pass the string argument as NULL
 */
