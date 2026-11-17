class Solution {
public:
    bool canWeReach(int n, vector<vector<pair<int, int>>> adj, int mid) {
        queue<int> q;
        vector<bool> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int neigh = adj[node][j].first;
                int w = adj[node][j].second;
                if (!visited[neigh] && w <= mid) {
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int maxiWeight = INT_MIN;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[v].push_back({u, wt});
            maxiWeight = max(maxiWeight, wt);
        }

        int low = 0;
        int high = maxiWeight;
        int result = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWeReach(n, adj, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};