class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix sum
        vector<int> suffix(n);
        suffix[n - 1] = piles[n - 1];

        for(int i = n - 2; i >= 0; i--){
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[index][M]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(piles, 0, 1, suffix, dp);
    }

    int helper(vector<int>& piles, int index, int M,
               vector<int>& suffix, vector<vector<int>>& dp) {

        if(index >= piles.size()) return 0;

        // ✅ DP check
        if(dp[index][M] != -1) return dp[index][M];

        int best = 0;

        for(int x = 1; x <= 2 * M && index + x <= piles.size(); x++) {

            int opponent = helper(piles, index + x, max(M, x), suffix, dp);

            int myStones = suffix[index] - opponent;

            best = max(best, myStones);
        }

        return dp[index][M] = best;
    }
};