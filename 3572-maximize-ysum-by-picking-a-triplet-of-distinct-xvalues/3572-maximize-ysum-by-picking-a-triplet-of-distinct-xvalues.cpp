class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {

        unordered_map<int, int> mp;
        set<int> st;

        // Store maximum y for each distinct x
        for (int i = 0; i < x.size(); i++) {

            st.insert(x[i]);

            mp[x[i]] = max(mp[x[i]], y[i]);
        }

        // Max heap
        priority_queue<int> pq;

        for (int val : st) {
            pq.push(mp[val]);
        }

        // Need at least 3 distinct x values
        if (pq.size() < 3) {
            return -1;
        }

        int ans = 0;

        // Pick top 3 maximum y values
        for (int i = 0; i < 3; i++) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};