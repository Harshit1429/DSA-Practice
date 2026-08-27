class Solution {
public:

    int ans = 0;

    int dirs[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<int>>& grid,
             int i,
             int j,
             vector<vector<bool>>& visited,
             long long& sum) {

        // Outside the grid
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size()) {
            return;
        }

        // Water or already visited
        if (grid[i][j] == 0 || visited[i][j]) {
            return;
        }

        // Mark visited
        visited[i][j] = true;

        // Add current cell value
        sum += grid[i][j];

        // Visit 4 directions
        for (auto& dir : dirs) {

            int r = i + dir[0];
            int c = j + dir[1];

            dfs(grid, r, c, visited, sum);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Start DFS for a new island
                if (grid[i][j] != 0 && !visited[i][j]) {

                    // Use long long because sum can be very large
                    long long sum = 0;

                    dfs(grid, i, j, visited, sum);

                    // Check if island sum is divisible by k
                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};