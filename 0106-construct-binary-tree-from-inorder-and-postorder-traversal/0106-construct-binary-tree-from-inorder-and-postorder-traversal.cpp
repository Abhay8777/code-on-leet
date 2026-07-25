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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &index, int startIdx, int endIdx,int n){
        if( index < 0|| startIdx> endIdx){
            return NULL;
        }
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = findpos(inorder, element, n);
        root->right = solve(inorder, postorder, index, position+1, endIdx, n);
        root->left = solve(inorder, postorder, index, startIdx, position-1, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n = inorder.size();
        int postOrderIdx = n-1;
        return solve(inorder, postorder, postOrderIdx, 0, n-1, n); 
    }
};