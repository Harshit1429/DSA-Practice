class Solution {
public:
    int N, M, K;
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int i, int searchCost, int maxSoFar) {
        if(searchCost > K)
            return 0;

        if (i == N)
            return searchCost == K ? 1 : 0;

        if (dp[i][searchCost][maxSoFar] != -1)
            return dp[i][searchCost][maxSoFar];

        int ways = 0;

        for (int curr = 1; curr <= M; curr++) {
            if (maxSoFar < curr)
                ways = (ways + solve(i + 1, searchCost + 1, curr)) % MOD;
            else
                ways = (ways + solve(i + 1, searchCost, maxSoFar)) % MOD;
        }

        return dp[i][searchCost][maxSoFar] = ways;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        K = k;
        M = m;
        dp.assign(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return solve(0, 0, 0);
    }
};