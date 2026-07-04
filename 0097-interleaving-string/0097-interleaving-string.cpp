class Solution {
public:

    vector<vector<int>> dp;

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        dp.resize(s1.length() + 1,
                  vector<int>(s2.length() + 1, -1));

        return helper(s1, s2, s3, 0, 0);
    }

    bool helper(string& s1, string& s2, string& s3,
                int m, int n) {

        if (m == s1.length() && n == s2.length()) {
            return true;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int k = m + n;

        bool ans = false;

        if (m < s1.length() &&
            s1[m] == s3[k]) {

            ans |= helper(s1, s2, s3, m + 1, n);
        }

        if (n < s2.length() &&
            s2[n] == s3[k]) {

            ans |= helper(s1, s2, s3, m, n + 1);
        }

        return dp[m][n] = ans;
    }
};