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
   void traversal(int i,TreeNode*root,vector<vector<int>>&out){
   
    if(root!=nullptr){
    out[i].push_back(root->val);
    traversal(i-1,root->left,out);
    traversal(i-1,root->right,out);
    }
    else
    return ;
   }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         int h=height(root);
         vector<vector<int>>out(h);
         traversal(h-1,root,out);
         return out;
    }
};