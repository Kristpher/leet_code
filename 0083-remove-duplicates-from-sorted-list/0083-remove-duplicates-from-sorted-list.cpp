/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        int unique = 1000;
        ListNode* ptr = head;
        ListNode* ptr2 = nullptr;

        while (ptr != nullptr && ptr->next != nullptr) {
            if (unique == ptr->val) {
                ptr2->next = ptr->next;
                ListNode* temp = ptr;
                ptr = ptr2->next;
                delete temp;
            } else {
                unique = ptr->val;
                ptr2 = ptr;
                ptr = ptr->next;
            }
        }

        if (unique == ptr->val && ptr2 != nullptr) {
            ptr2->next = nullptr;
            delete ptr;
        }

        return head;
    }
};
