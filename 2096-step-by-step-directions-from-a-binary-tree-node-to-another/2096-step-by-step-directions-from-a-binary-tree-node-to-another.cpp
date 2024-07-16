class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        TreeNode* startNode = nullptr;

        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode->val == startValue) {
                startNode = currentNode;
                break;
            }

            if (currentNode->left) {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                nodeQueue.push(currentNode->right);
            }
        }

        unordered_map<int, TreeNode*> parentNodeMap;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode->left) {
                parentNodeMap[currentNode->left->val] = currentNode;
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                parentNodeMap[currentNode->right->val] = currentNode;
                nodeQueue.push(currentNode->right);
            }
        }

        unordered_set<TreeNode*> visitedNodes;
        nodeQueue.push(startNode);
        unordered_map<TreeNode*, pair<TreeNode*, char>> pathTracker;

        TreeNode* destinationNode = nullptr;

        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
            visitedNodes.insert(currentNode);

            if (currentNode->val == destValue) {
                destinationNode = currentNode;
                break;
            }

            if (parentNodeMap.find(currentNode->val) != parentNodeMap.end() && visitedNodes.find(parentNodeMap[currentNode->val]) == visitedNodes.end()) {
                TreeNode* parent = parentNodeMap[currentNode->val];
                nodeQueue.push(parent);
                pathTracker[parent] = make_pair(currentNode, 'U');
            }

            if (currentNode->left && visitedNodes.find(currentNode->left) == visitedNodes.end()) {
                nodeQueue.push(currentNode->left);
                pathTracker[currentNode->left] = make_pair(currentNode, 'L');
            }

            if (currentNode->right && visitedNodes.find(currentNode->right) == visitedNodes.end()) {
                nodeQueue.push(currentNode->right);
                pathTracker[currentNode->right] = make_pair(currentNode, 'R');
            }
        }

        stack<char> resultPath;
        TreeNode* currentNode = destinationNode;

        while (currentNode != startNode) {
            auto it = pathTracker.find(currentNode);
            if (it != pathTracker.end()) {
                resultPath.push(it->second.second);
                currentNode = it->second.first;
            }
        }

        string res;
        while (!resultPath.empty()) {
            res += resultPath.top();
            resultPath.pop();
        }

        return res;
    }
};
