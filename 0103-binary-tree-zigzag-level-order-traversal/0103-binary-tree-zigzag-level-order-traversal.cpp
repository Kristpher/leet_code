#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {}; 
        
        queue<TreeNode*> q;
        vector<vector<int>> out;
        q.push(root);
        bool check = true;
        
        while (!q.empty()) {
            int l = q.size();
            vector<int> v(l);
            
            for (int i = 0; i < l; i++) {
                TreeNode* ptr = q.front();
                q.pop();
                int ind = check ? i : l - i - 1;
                v[ind] = ptr->val;
                
                if (ptr->left)
                    q.push(ptr->left);
                if (ptr->right)
                    q.push(ptr->right);
            }
            
            out.push_back(v); 
            check = !check; 
        }
        
        return out;
    }
};
