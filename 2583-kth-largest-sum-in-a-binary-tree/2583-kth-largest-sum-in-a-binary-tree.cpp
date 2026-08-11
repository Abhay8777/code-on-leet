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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>result;
        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            for(int i = 0;i<n;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                sum+=frontNode->val;
                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
            }
            result.push_back(sum);
        }
        if(result.size()<k) return -1;
        sort(begin(result),end(result),greater<long long>());
        return result[k-1];
    }
};