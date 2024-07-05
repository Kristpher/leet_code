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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v(2,-1);
        if(head!=nullptr){
        ListNode*ptr=head;
        int val=head->val;
        ptr=ptr->next;
        int c1=0;
        int c2=0;
        int count=0;
        int minim=INT_MAX;
        int i=2;
        while(ptr->next!=NULL){
            int flag=0;
            if(ptr->val<ptr->next->val&&ptr->val<val||ptr->val>ptr->next->val&&ptr->val>val){
              if(count==0){  
              c1=i;
              count++;
              }
              if(count==1 &&c1!=i){
                c2=i;
                count=0;
              }
              if(minim>abs(c1-c2)&&c1!=0&&c2!=0){
                minim=abs(c1-c2);
                v[0]=minim;
                
              }
              if(v[1]<abs(c1-c2)&&v[1]==-1&&c1!=0&&c2!=0){
                v[1]=abs(c1-c2);
                flag=1;
              }
              if(v[1]!=-1&&c1!=0&&c2!=0&&!flag){
                v[1]+=abs(c1-c2);
                
              }
            }
            val=ptr->val;
            ptr=ptr->next;
            i++;
        }
        }
        return v;
    }
};