class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* ptr = head;
        ListNode* ptr2 = head;
        ListNode* prev = nullptr;

        while (ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr2 != NULL) {
            ptr = ptr->next;
        }

        prev->next = nullptr;
        ptr2 = nullptr;

        while (ptr != NULL) {
            ListNode* next = ptr->next;
            ptr->next = ptr2;
            ptr2 = ptr;
            ptr = next;
        }

        ptr = head;

        while (ptr2 != NULL) {
            if ( ptr->val != ptr2->val) {
                return false;
            }
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }

        return true;
    }
};
