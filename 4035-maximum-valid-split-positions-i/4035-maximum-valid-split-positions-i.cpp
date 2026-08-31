class Solution {
public:

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        // Try removing nothing and every one element
        for (int remove = -1; remove < n; remove++) {

            vector<int> arr;

            // Build array after removal
            for (int i = 0; i < n; i++) {
                if (i != remove) {
                    arr.push_back(nums[i]);
                }
            }

            int m = arr.size();

            // An array of length 1 has no split
            if (m < 2)
                continue;

            // Prefix GCD
            vector<int> pre(m);
            pre[0] = arr[0];

            for (int i = 1; i < m; i++) {
                pre[i] = gcd(pre[i - 1], arr[i]);
            }

            // Suffix GCD
            vector<int> suff(m);
            suff[m - 1] = arr[m - 1];

            for (int i = m - 2; i >= 0; i--) {
                suff[i] = gcd(suff[i + 1], arr[i]);
            }

            int count = 0;

            // Try every split
            for (int i = 0; i < m - 1; i++) {

                if (pre[i] == suff[i + 1]) {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};