class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL || (head->next == NULL && head->val == val))
            return NULL;
        ListNode* ptr = head;
        ListNode* ptr2 = nullptr;
        while (ptr != NULL) {
            if (ptr->val == val) {
                if (head == ptr) {
                    head = head->next;
                }
                else {
                    ListNode*temp=ptr;
                    ptr2->next=ptr->next;
                    ptr=ptr2;
                    delete temp;
                }
            }
            ptr2 = ptr;
            ptr = ptr->next;
        }
       return head;
    }
};