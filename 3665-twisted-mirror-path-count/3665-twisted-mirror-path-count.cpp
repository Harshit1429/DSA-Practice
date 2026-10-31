class Solution {
public:
    int n, m;
    int mod = 1000000007;

    long long dp[505][505][2];

    long long solve(vector<vector<int>>& grid, int i, int j, int dir) {

        if (i >= n || j >= m)
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;

        if (grid[i][j] == 1) {

            if (dir == 0)
                ans = solve(grid, i + 1, j, 1);
            else
                ans = solve(grid, i, j + 1, 0);

        } else {

            long long down = solve(grid, i + 1, j, 1);
            long long right = solve(grid, i, j + 1, 0);

            ans = (down + right) % mod;
        }

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        long long ans = solve(grid, 0, 0, 0);

        return ans % mod;
    }
};