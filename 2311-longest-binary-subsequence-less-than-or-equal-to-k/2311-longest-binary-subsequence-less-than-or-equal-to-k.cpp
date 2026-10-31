class Solution {
public:
    int longestSubsequence(string s, int k) {

        long long sum = 0;
        long long power = 1;
        int ans = 0;

        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] == '0') {
                ans++;
            }
            else {
                if (sum + power <= k) {
                    sum += power;
                    ans++;
                }
            }

            if (power <= k) {
                power *= 2;
            }
        }

        return ans;
    }
};