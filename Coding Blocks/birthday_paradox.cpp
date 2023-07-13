/* Birthday paradax problem
 * Find the minimum no of people for that should be present so that there is
 * p % chance for two persons to have same birthdays
 * 
 * Do it with respect to no persons having same birthday
 * */
#include<iostream>
using namespace std;
int main()
{
    double x=1.0; // probabity of 2 persons having the same birthday
    int persons=0;
    double num=365; // numerator initially
    double p;
    cout<<"Enter the % chance for two persons to have same birthday\n";
    cin>>p;
    p=(float)p/100.0;
    while(1-p<x) // while the probability doesn't dip below the minimum allowed value (1-p)
    {
        x*=num/365;
        num--;
        persons++;
    }
    cout<<persons<<" persons\n";
    return 0;
}
/*
 * p--> probability that two persons have same birthday
 * ~p or (1-p) --> probability that persons have different birthdays 
 * ~p is complement of p
 *
 * Atleast two people having the same birthday is complement of all people having different birthdays
 *
 * When n=1 person then there is no chance that his birthday will collide will another person because he
 * is the only person...so the probability for him is 1.0 
 * which implies it is certain his birthday will not collide....his birthday is unique 
 *
 * The probability should be atleast p/100 so we run a while loop till it's greater than (1-p)/100
 * Greater the number of people more are the chances for same birthday 
 * */
