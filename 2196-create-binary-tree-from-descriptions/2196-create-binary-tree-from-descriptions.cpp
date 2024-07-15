class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map1;
        unordered_map<int, int> map2;

        for (int i = 0; i < descriptions.size(); i++) {
            int parentVal = descriptions[i][0];
            int childVal = descriptions[i][1];
            bool isLeft = descriptions[i][2];

    
            if (!map1[parentVal]) {
                map1[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* root = map1[parentVal];

       
            if (!map1[childVal]) {
                map1[childVal] = new TreeNode(childVal);
            }
            TreeNode* child = map1[childVal];

        
            if (isLeft) {
                root->left = child;
            } else {
                root->right = child;
            }

         
            map2[childVal]++;
        }

        TreeNode* ptr = nullptr;
        for (int i = 0; i < descriptions.size(); i++) {
            int p = descriptions[i][0];
            if (!map2.count(p)) {
                ptr = map1[p];
                break;
            }
        }

        return ptr;
    }
};