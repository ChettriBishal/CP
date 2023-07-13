/* 
Now, we'll try to solve a famous stack problem.
You are given an array A of size N. 
You need to first push the elements of the array into a stack and then print minimum in the stack at each pop.
*/

//Function to push all the elements into the stack.
stack<int> _push(int a[],int n)
{
   int minval = a[0];
   stack<int> s;
    for(int i= 0;i<n;i++){
        int val= min(minval,a[i]);
        s.push(val); // inserting the minimum value so far
        minval = min(minval,a[i]);
    }
    return s;
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

/*
Input:
N = 5
A = {1 2 3 4 5}
Output: 
1 1 1 1 1
Explanation: 
After pushing elements to the stack, 
the stack will be "top -> 5, 4, 3, 2, 1". 
Now, start popping elements from the stack
popping 5: min in the stack is 1.popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
*/
