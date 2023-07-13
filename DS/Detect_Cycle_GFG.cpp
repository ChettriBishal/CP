#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

int countNodes(struct Node* start)
{
    Node* trav = start;
    int cnt = 1;
    while(trav->next != start){
        trav = trav ->next;
        cnt++;
    }
    return cnt;
}
//Function to find the length of a loop in the linked list.
// Floyd’s Cycle-Finding Algorithm:  
int countNodesinLoop(struct Node *head)
{
    struct Node* slow = head, *fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast ->next->next;
        if(fast == slow){
            return countNodes(fast);
        }
    }
    
    return 0;
    
}
