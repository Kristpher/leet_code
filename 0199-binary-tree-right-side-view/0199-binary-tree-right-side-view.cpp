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
vector<int>v;
int height(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else {
        int lefth = height(root->left);
        int righth = height(root->right);
        return (lefth > righth) ? (lefth + 1) : (righth + 1);
    }
}

void travel(TreeNode* root, int level,int *count) {
    if (root == nullptr)
        return;
    
    else if (level >= 1) {
        travel(root->left, level - 1,count);
        travel(root->right, level - 1,count);
        
    }
    if(level-1==0)
     {
        *count=root->val;
     }
    
}

void level(TreeNode* root) {
    int h = height(root);
    int count=0;
    for (int i = 1; i <= h; i++)
    {
          int count=-1;
        travel(root, i,&count);
        if(count!=-1)
        v.push_back(count);
    }
}
    vector<int> rightSideView(TreeNode* root) {
       level(root);
       return v;          
    }
};