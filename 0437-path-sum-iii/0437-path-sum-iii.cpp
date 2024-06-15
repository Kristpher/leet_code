class Solution {
public:
    int count=0;
    void treesum(TreeNode* root, int targetSum,vector<long long>v)
    {
        
        if(root==nullptr)
        return ;
        v.push_back(root->val);
        treesum(root->left,targetSum,v);
        treesum(root->right,targetSum,v);
        long long sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
           sum+=v[i];
           if(sum==targetSum)
           count++;
        }
        v.pop_back();
        }
    int pathSum(TreeNode* root, int targetSum) {
        
         vector<long long>v;
         treesum(root,targetSum,v);
         return count;
    }
};