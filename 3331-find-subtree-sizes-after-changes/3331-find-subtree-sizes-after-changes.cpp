class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;

        vector<vector<int>> pos(26);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            if (!pos[c].empty()) {
                newParent[u] = pos[c].back();
            }

            pos[c].push_back(u);

            for (int v : tree[u]) {
                dfs(v);
            }

            pos[c].pop_back();
        };

        dfs(0);

        vector<vector<int>> finalTree(n);
        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n);

        function<int(int)> dfsSize = [&](int u) {
            int sz = 1;

            for (int v : finalTree[u]) {
                sz += dfsSize(v);
            }

            return ans[u] = sz;
        };

        dfsSize(0);

        return ans;
    }
};