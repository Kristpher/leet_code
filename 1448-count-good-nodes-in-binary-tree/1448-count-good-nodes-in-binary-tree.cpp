/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* root, int maxim) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;
        if (root->val >= maxim) {
            count = 1;
            maxim = root->val;
        }

        return count + check(root->left, maxim) + check(root->right, maxim);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return check(root, root->val);
    }
};
