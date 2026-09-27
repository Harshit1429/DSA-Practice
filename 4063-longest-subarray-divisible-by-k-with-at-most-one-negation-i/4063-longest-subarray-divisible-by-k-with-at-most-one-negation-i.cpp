class Solution {
public:
    int longestSubarray(vector<int>& A, int k) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            int s = 0;
            unordered_set<int> seen;
            for (int j = i; j < n; ++j) {
                s = ((s + A[j]) % k + k) % k;
                seen.insert(((A[j] * 2) % k + k) % k);
                if (s == 0 || seen.count(s)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }};