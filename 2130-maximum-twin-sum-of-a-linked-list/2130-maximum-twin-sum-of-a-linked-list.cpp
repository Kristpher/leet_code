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
    int pairSum(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;
\
        while (ptr != nullptr) {
            ptr = ptr->next;
            len++;
        }

        ptr = head;
        ListNode* temp = head;
        int size = len;
        int start = 0;

  
        while (start != (size / 2) - 1) {
            start++;
            temp = temp->next;
        }

        ListNode* mid_list = temp->next; 
        temp->next = nullptr;

    
        ListNode* prev = nullptr;
        ListNode* curr = mid_list;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int maxsum = 0;

     
        temp = prev;
        while (temp != nullptr) {
            int sum = temp->val + ptr->val;
            maxsum = max(maxsum, sum);
            ptr = ptr->next;
            temp = temp->next;
        }

        return maxsum;
    }
};
