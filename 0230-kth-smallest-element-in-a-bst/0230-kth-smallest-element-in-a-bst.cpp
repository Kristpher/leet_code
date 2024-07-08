class Solution {
public:
    void in(TreeNode* root, int &k, int &val) {
        if (root != nullptr) {
            in(root->left, k, val);
            
            k--;
            if (k == 0) { 
                val = root->val;
                return;
            }
            
            in(root->right, k, val);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int val = -1;
        in(root, k, val);
        return val;
    }
};
