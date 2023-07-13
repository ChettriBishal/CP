DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* prev ,*next,*cur;
    cur= llist;
    prev = NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
    }
    return prev;
}
