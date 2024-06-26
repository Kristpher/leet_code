/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }

    void traversal(int level, TreeNode* root, vector<vector<int>>& out, bool leftToRight) {
        if (root == nullptr) return;
        
        out[level].push_back(root->val);
        
        if (leftToRight) {
            traversal(level + 1, root->left, out, !leftToRight);
            traversal(level + 1, root->right, out, !leftToRight);
        } else {
            traversal(level + 1, root->right, out, !leftToRight);
            traversal(level + 1, root->left, out, !leftToRight);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> out(h);
        traversal(0, root, out, false);  
        return out;
    }
};
