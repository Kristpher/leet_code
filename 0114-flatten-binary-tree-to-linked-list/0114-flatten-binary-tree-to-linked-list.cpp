class Solution {
public:
    void pre(TreeNode* root, queue<TreeNode*>& q) {
        if (root != nullptr) {
            q.push(root);           
            pre(root->left, q);     
            pre(root->right, q);     
        }
    }
    
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        pre(root, q);  

        TreeNode* current = q.front();
        q.pop();
        
        while (!q.empty()) {
            current->left = nullptr;   
            current->right = q.front(); 
            q.pop();
            current = current->right;  
        }
    }
};
