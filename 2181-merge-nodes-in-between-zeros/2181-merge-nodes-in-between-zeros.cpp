class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head->next;
        int count = 0;
        int sum=0;
        ListNode* zero = head;
       while (ptr != nullptr) {
            if (ptr->val == 0) {
                ptr->val = sum;
                sum=0;
                zero->next = ptr;
                zero = ptr;
            } else 
                sum += ptr->val;
            
            ptr=ptr->next;
        }
     return head->next;
}
}
;