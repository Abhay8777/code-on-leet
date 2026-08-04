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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;  
        int dx = -1, dy = -1;    
        
        dfs(root, nullptr, 0, x, px, dx);
        dfs(root, nullptr, 0, y, py, dy);
        
        return dx == dy && px != py;
    }
    void dfs(TreeNode* node, TreeNode* parent, int depth,
             int target, TreeNode*& p, int& d) {
        if (!node) return;
        if (node->val == target) {
            p = parent;
            d = depth;
            return;
        }
        dfs(node->left, node, depth+1, target, p, d);
        dfs(node->right, node, depth+1, target, p, d);
    }
};
