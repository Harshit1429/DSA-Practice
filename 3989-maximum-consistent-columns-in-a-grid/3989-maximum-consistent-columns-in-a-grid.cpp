class Solution {
public:
    bool check(vector<vector<int>>&grid, int a, int b, int &limit) {
        int n = grid.size();

        for(int i=0; i<n; i++) {
            if( abs(grid[i][a] - grid[i][b]) > limit) return false;
        }

        return true;
    }

    int memo(vector<vector<int>>&grid, int limit, vector<vector<int>>&dp, int prev, int curr) {
        //base case? 
        int m = grid[0].size();
        if(curr == m) return 0;

        //vis case
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        int giveup = memo(grid, limit, dp, prev, curr+1);
        int keep = 0;
        
        if(prev == -1 || check(grid, prev, curr, limit)) {
            keep = 1 + memo(grid, limit, dp, curr, curr+1);
        }

        return dp[prev+1][curr] = max(keep, giveup);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        //from the problem what i can do is.
        //check for each column from start until we found any | grid[i][b] - grid[i][a] | > limit 
        //then i have 2 choice there, either keep that column or give up
        //case 1 : when kept, we move to next columns
        //again till the condition is true, we keep moving, then we encounter again and we have 2 choices again.

        //Its simply keep or give up. Simple DP would work. 

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(m+1, -1)); 
        return memo(grid, limit, dp, -1, 0);
    }
};