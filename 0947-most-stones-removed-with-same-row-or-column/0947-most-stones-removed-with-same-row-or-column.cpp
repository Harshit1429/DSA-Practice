class Solution {
public:
    int dfs(vector<vector<int>>& stones, int index, vector<bool>& visited, int n) {
        visited[index] = true;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
                res += 1 + dfs(stones, i, visited, n);
            }
        }
        return res;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<bool> visited(n, false);
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            res += dfs(stones, i, visited, n);
        }
        
        return res;
    }
};