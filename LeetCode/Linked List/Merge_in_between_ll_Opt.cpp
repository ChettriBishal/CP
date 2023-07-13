class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pa, *pb;
        pa = pb = list1;
        for(int i=0;i<a-1;i++)
            pa = pa->next;
        for(int i=0;i<b;i++)
            pb = pb ->next;
        pa->next = list2;
        
        while(list2->next){
            list2 = list2->next;
        }
        list2 ->next = pb->next;
        return list1;
    }
};
