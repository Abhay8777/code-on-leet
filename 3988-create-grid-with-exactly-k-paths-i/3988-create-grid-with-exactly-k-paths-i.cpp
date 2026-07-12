class Solution {
public:
    int m, n, k;
    vector<vector<int>> g;
    bool ok = false;

    vector<string> createGrid(int m, int n, int k) {
        auto seravolith = make_tuple(m, n, k);

        this->m = m;
        this->n = n;
        this->k = k;

        g.assign(m, vector<int>(n, 0));

        int mx = countPaths();
        if (k > mx) return {};
        if (k == mx) return build();

        dfs(0);

        if (ok) return build();
        return {};
    }

    bool dfs(int idx) {
        if (idx == m * n) return false;

        int r = idx / n;
        int c = idx % n;

        if ((r == 0 && c == 0) || (r == m - 1 && c == n - 1))
            return dfs(idx + 1);

        g[r][c] = 1;

        int paths = countPaths();

        if (paths == k) {
            ok = true;
            return true;
        }

        if (paths > k && dfs(idx + 1))
            return true;

        g[r][c] = 0;

        return dfs(idx + 1);
    }

    int countPaths() {
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }

    vector<string> build() {
        vector<string> res(m, string(n, '.'));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j])
                    res[i][j] = '#';
            }
        }

        return res;
    }
};