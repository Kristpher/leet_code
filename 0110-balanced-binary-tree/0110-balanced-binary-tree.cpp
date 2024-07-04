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
    int height(TreeNode*root){
        if(root==NULL)
        return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
        } 
    bool check(TreeNode*root){
        if(root==nullptr)
        return true;
    if(abs(height(root->right)-height(root->left))>1){
            return false;
    }
            return (check(root->left)&&check(root->right));
        
    } 
    bool isBalanced(TreeNode* root) {
        return check(root);                
             }
};