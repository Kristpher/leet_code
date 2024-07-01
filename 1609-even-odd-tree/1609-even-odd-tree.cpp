class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        int h = height(root);
        if (h == 1 ){
           if(root->val%2!=0)
            return true;
            else
            return false;
        } 
        
        queue<TreeNode*> q;
        q.push(root);
        
        for (int level = 1; level <= h; level++) {
            int currentLevelSize = q.size();
            int prevVal = (level % 2 == 1) ? INT_MIN : INT_MAX; 
            
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
             
                if ((level % 2 == 1 && (node->val % 2 == 0 || node->val <= prevVal)) ||
                    (level % 2 == 0 && (node->val % 2 == 1 || node->val >= prevVal))) {
                    return false;
                }
          
                prevVal = node->val;
                
              
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return true;
    }
};
