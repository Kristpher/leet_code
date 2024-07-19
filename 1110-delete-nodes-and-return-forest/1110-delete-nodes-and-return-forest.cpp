class Solution {
public:
    bool val[1001]={};
    void pre(TreeNode* &root,bool flag, vector<TreeNode*>&v){
        if(root==nullptr)
        return;
        else{
        pre(root->left,val[root->val],v);
        pre(root->right,val[root->val],v);
        if(!val[root->val]&&flag) 
        v.push_back(root);
         if(val[root->val]) 
        root=nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>v;
      for(int i:to_delete)
        val[i]=true;
        pre(root,true,v);
        return v;
    }
};