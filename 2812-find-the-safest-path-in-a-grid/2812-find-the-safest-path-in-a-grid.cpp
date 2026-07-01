class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
    
    bool isValid(vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
            return false;
        return true;
    }
    
    bool isSafe(vector<vector<int>>& distToTheif, int safeDist) {
        
        queue<pair<int, int>> q;
        
        if (distToTheif[0][0] < safeDist)
            return false;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            if (currRow == n - 1 && currCol == n - 1) 
                return true;
            
            for (auto& dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];
                if (isValid(visited, newRow, newCol)) {
                    if (distToTheif[newRow][newCol] < safeDist) continue;
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid)  {
        n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> distToTheif(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)  {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int currRow = q.front().first, currCol = q.front().second;
                q.pop();
                distToTheif[currRow][currCol] = dist;
                for (auto& dir : directions) {
                    int newRow = currRow + dir[0], newCol = currCol + dir[1];
                    if (!isValid(visited, newRow, newCol)) continue;
                    
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            dist++;
        }
        
        int low = 0;
        int high = 400;
        int result = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (isSafe(distToTheif, mid)) {
                result = mid;
                low    = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;  
    }
};