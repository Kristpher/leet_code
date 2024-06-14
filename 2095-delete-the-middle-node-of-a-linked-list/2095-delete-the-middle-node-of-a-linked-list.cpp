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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*ptr=head;
        if(ptr->next==nullptr)
        return head;
        int len=0;
        while(ptr!=nullptr)
        {
            
            ptr=ptr->next;
             len++;
           
        }
        int mid=floor(len/2);
       ptr=head;
       int var=0;
       while(var!=mid-1)
       {
        
        ptr=ptr->next;
        var++;
       }
      ptr->next=ptr->next->next;
      return head;
    }
};