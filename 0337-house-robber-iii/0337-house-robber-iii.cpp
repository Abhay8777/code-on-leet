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
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>left = dfs(root->left);
        pair<int,int>right = dfs(root->right);
        pair<int,int>res;
        res.first = root->val + left.second + right.second;
        res.second =max(left.first,left.second)  + max(right.first, right.second);
        return res;
    }
    
    int rob(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return max(res.first, res.second);
    }
};
