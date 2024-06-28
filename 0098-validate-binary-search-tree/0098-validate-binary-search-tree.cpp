class Solution {
public:
    bool bst(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

  
        bool leftValid = bst(root->left, minVal, root->val);
        bool rightValid = bst(root->right, root->val, maxVal);

     
        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN, LLONG_MAX);   
    }
};
