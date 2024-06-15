class Solution {
public:
    TreeNode* search(TreeNode* root, int k) {
        if (root == nullptr || root->val == k)
            return root;
        if (k < root->val)
            return search(root->left, k);
        else
            return search(root->right, k);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
