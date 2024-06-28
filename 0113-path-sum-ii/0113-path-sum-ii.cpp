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
   void add(TreeNode* root,    vector<vector<int>>&out,vector<int>&v,int targetSum,int sum)
   {
    if(root==nullptr)
    {
     return;

    }
    else{
        sum+=root->val;
        v.push_back(root->val);
        if(root->right==nullptr &&root->left==nullptr)
        {
            if(sum==targetSum)
            {
                out.push_back(v);
            }
        }
        add(root->left,out,v,targetSum,sum);
        add(root->right,out,v,targetSum,sum);
        v.pop_back();

    }
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>out;
        vector<int>v;
        int sum=0;
        add(root,out,v,targetSum,sum);
        return out;
    }
};