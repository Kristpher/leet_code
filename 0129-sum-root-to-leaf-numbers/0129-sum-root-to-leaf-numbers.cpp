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
    int add(vector<int>&v)
    {
        int j=0;
        int summ=0;
        for(int i=v.size()-1;i>=0;i--)
        {
           summ+=v[i]*pow(10,j);
           j++;
        }
        return summ;
    }

    void calc(TreeNode*root,int &sum,vector<int>&v)
    {
        if(root==NULL)
        {
          return;
        }
        else{
            v.push_back(root->val);
           if(root->right==NULL && root->left==NULL)
           {   int val=add(v);
               cout<<val<<endl;
               sum+=val;
           }
           calc(root->left,sum,v);
          
           calc(root->right,sum,v);
            v.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int i=0;
        int val=0;
        vector<int>v;
        calc(root,sum,v);
        return sum;
    }
};