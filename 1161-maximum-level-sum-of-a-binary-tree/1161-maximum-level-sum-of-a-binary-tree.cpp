class Solution {
public:
    int maxim = INT_MIN;
    int maxLevel = 0; 

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            return max(leftHeight, rightHeight) + 1; 
        }
    }

    void travel(TreeNode* root, int level, int& sum) {
        if (root == nullptr)
            return;
        
        if (level == 1) {
            sum += root->val; 
        } else if (level > 1) {
            travel(root->left, level - 1, sum);
            travel(root->right, level - 1, sum); 
        }
    }

    void level(TreeNode* root) {
        int h = height(root); 
        for (int i = 1; i <= h; i++) {
            int levelSum = 0;
            travel(root, i, levelSum);

            if (levelSum > maxim) {
                maxim = levelSum;
                maxLevel = i;
            }
        }
    }

    int maxLevelSum(TreeNode* root) {
        level(root); 
        return maxLevel; 
    }
};
