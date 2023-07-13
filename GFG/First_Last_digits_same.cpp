// https://www.geeksforgeeks.org/count-numbers-first-last-digits/
#include<bits/stdc++.h>
using namespace std;

int getfirstdigit(int n)
{
    while( n >= 10 ){
        n /=10;
    }

    return n;
}

// count of the numbers from 1 to n with the same starting and ending digits
int count_starting_from_1(int n)
{
    if(n<10){
        return n;
    }

    // get ten spans from 1 to x
    int tens = n/10;
    
    // add the 1 - 9 numbers inclusive 
    int res = tens+9;
    int firstdigit = getfirstdigit(n);
    int lastdigit = n % 10;

    // if the last digit is smaller than first digit then decrease the count by 1
    if( lastdigit < firstdigit)
        res--;
    return res;
}

int count_starting_from_s_e(int start,int end)
{
    return count_starting_from_1(end) - count_starting_from_1(start-1); 
}

int main()
{
    int start,end;
    cin>>start>>end;
    
    cout<<count_starting_from_s_e(start,end)<<endl;

    return 0;

}
