class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    
    void level(TreeNode* root, long long& valu, int h) {
        if (root == nullptr)
            return;
        if (h == 1 && valu == LLONG_MIN) {
            valu = root->val;
        }
        if (valu != LLONG_MIN)
            return;
        level(root->left, valu, h - 1);
        level(root->right, valu, h - 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        long long valu = LLONG_MIN;
        level(root, valu, h);
        return valu;
    }
};