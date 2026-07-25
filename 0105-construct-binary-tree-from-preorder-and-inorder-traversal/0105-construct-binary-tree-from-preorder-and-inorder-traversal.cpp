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
     int findpos(vector<int> &inorder, int elem, int n){
        for(int i = 0;i<n; i++){
            if(inorder[i] == elem) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderstart, int inorderlast, int n){
        if(index>=n || inorderstart>inorderlast) return NULL;
        
        int elem = preorder[index++];
        TreeNode* root = new TreeNode(elem);
        int position = findpos(inorder, elem, n);
        
        root->left = solve(inorder, preorder, index, inorderstart, position-1, n);
        root->right = solve(inorder, preorder, index, position+1, inorderlast, n);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        return solve(inorder, preorder, preOrderIndex, 0, n-1, n);
    }
};