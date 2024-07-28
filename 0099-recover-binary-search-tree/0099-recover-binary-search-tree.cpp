class Solution {
public:
    void in(TreeNode* root, TreeNode*& temp1, TreeNode*& temp2, TreeNode*& prev) {
        if (root == nullptr) {
            return;
        }
        
        in(root->left, temp1, temp2, prev);

        if (prev && root->val < prev->val) {
            if (!temp1) {
                temp1 = prev; 
            }
            temp2 = root;  
        }
        
        prev = root; 
        
        in(root->right, temp1, temp2, prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* temp1 = nullptr;
        TreeNode* temp2 = nullptr;
        TreeNode* prev = nullptr;

        in(root, temp1, temp2, prev);
     
        if (temp1 && temp2) {
            swap(temp1->val, temp2->val);
        }
    }
};