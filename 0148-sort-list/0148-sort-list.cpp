class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;

        ListNode *temp = head;
        while (temp != nullptr) {
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(v.begin(), v.end());

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp -> val = v[i++];
            temp = temp -> next;
        }

        return head;
    }
};