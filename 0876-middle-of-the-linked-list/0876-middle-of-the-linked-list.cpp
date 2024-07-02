class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ptr2 = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            ptr = ptr->next->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
    }
};