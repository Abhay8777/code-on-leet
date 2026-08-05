class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);

        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            edges[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {
            int curr = que.front(); 
            que.pop();
            for (int& ngbr : edges[curr]) {
                inDegree[ngbr]--; //removing all edges within suspicious group
                if (!suspicious[ngbr]) { 
                    que.push(ngbr); 
                    suspicious[ngbr] = true; 
                }
            }
        }

        vector<int> result;
        bool regularTosuspicious = false;
        for (int i = 0; i < n; i++) {

            if (suspicious[i] && inDegree[i] > 0) {   // regular to suspicious edge exists
                regularTosuspicious = true;
                break;
            }

            if (!suspicious[i]) 
                result.push_back(i);
        }

        if(regularTosuspicious) {
            vector<int> fullNodes(n); //can use iota as well
            for (int i = 0; i < n; i++) 
                fullNodes[i] = i;

            return fullNodes;
        }
        
        return result;
    }
};