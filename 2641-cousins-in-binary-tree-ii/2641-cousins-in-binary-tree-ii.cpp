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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        
        queue<TreeNode*> q;
        root->val = 0;  
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0;
            vector<TreeNode*> nodes;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                nodes.push_back(node);
                if (node->left) {
                    levelSum += node->left->val;
                }
                if (node->right) {
                    levelSum += node->right->val;
                }
            }
            for (auto node : nodes) {
                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;
                
                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
