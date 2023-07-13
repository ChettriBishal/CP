
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
    temp->next = temp->prev = NULL;
    
    // if it's the first node
    if(llist == NULL)
        return temp;
    
    // if the data is the smallest in the list
    if(data < llist->data){
        temp->next = llist;
        llist->prev = temp;
        llist = temp;
        return llist;
    }
    // else we need to traverse ahead --->
    
    DoublyLinkedListNode* ahead = sortedInsert(llist->next, data);
    llist->next = ahead;
    ahead->prev = llist;
    return llist;
    
}

// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem
