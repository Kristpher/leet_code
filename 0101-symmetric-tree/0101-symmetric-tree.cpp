class Solution {
public:
    bool pre(TreeNode* rootl, TreeNode* rootr) {
        if (rootl == nullptr && rootr == nullptr)
            return true;
        if (rootl == nullptr || rootr == nullptr)
            return false;
        if (rootl->val != rootr->val)
            return false;
        return pre(rootl->left, rootr->right) && pre(rootl->right, rootr->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return pre(root->left, root->right);
    }
};
