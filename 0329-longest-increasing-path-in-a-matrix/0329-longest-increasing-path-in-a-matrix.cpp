#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    
    int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& memo, int r, int c) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }
        
        int max_len = 1;
        int current_val = matrix[r][c];
        
        for (const auto& dir : DIRS) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > current_val) {
                max_len = max(max_len, 1 + dfs(matrix, memo, nr, nc));
            }
        }
        
        return memo[r][c] = max_len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        // Flattening to a 1D vector or using a flat array can improve cache locality,
        // though a 2D vector is clean and already runs in ~15-25ms.
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        
        return ans;
    }
};