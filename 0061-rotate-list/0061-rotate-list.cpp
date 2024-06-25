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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        return head;
        ListNode* ptr = head;
        int len = 0;
        ListNode* ptr2 = nullptr;
        while (ptr != nullptr) {
            ptr2 = ptr;
            ptr = ptr->next;
            len++;
        }
        int p = k % len;
        if (p == 0)
            return head;

        ptr = head;
        int l = 1;
        while (l != len - p) {
            ptr = ptr->next;
            l++;
        }
        cout << ptr->val;
        ListNode* temp = ptr->next;
        ptr2->next = head;
        head = temp;
        ptr->next = nullptr;
        return head;
    }
};