/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)  {
       ListNode *ptr=head;
       int i=0;
       
       while(ptr!=nullptr && ptr->val!=INT_MAX)
       {
        
        if(ptr->val>100000)
        {
           break;
        }
        ptr->val=i+1000000;
        i++;
        ptr=ptr->next;
        
      } 
    if(ptr!=nullptr)   
    return ptr;
    return NULL;
    }
};