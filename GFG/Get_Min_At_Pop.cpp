/*
Now, we'll try to solve a famous stack problem.
You are given an array A of size N. 
You need to first push the elements of the array into a stack and then print minimum in the stack at each pop.
*/
#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

//Function to push all the elements into the stack.
stack<int> _push(int a[],int n)
{
   int minval = a[0];
   stack<int> res;
   for(int i=0;i<n;i++){
       res.push(min(minval,a[i]));
       minval = min(minval,a[i]);
   }
   return res;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
   while(!s.empty()){
       cout<<s.top()<<" ";
       s.pop();
   }
   cout<<endl;
   
   
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends
