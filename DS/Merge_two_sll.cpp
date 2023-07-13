
// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* res=NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    if(head1->data < head2->data){
        res=head1;
        res->next=mergeLists(head1->next,head2);
    }
    else{
        res=head2;
        res->next=mergeLists(head1,head2->next);
    }
    return res;
}

