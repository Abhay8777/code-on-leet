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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>rightView;
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<TreeNode*, int>temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int lvl = temp.second;
            if(rightView.find(lvl) == rightView.end()){
                rightView[lvl] = frontNode->val;
            }
            if(frontNode->right) q.push(make_pair(frontNode->right, lvl+1));
            if(frontNode->left) q.push(make_pair(frontNode->left, lvl+1));
            
        }
        for(auto i:rightView){
            ans.push_back(i.second);
        }
        return ans;
    }
};