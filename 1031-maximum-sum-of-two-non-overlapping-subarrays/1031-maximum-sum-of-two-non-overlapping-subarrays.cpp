class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            sums[i] = nums[i - 1] + sums[i - 1];
        }

        int maxLval = 0;
        int ans = 0;
        for (int i = firstLen; i <= n - secondLen; i++) {
            maxLval = max(maxLval, sums[i] - sums[i - firstLen]);
            ans = max(ans, sums[i + secondLen] - sums[i] + maxLval);
        }

        int maxRval = 0;
        for (int i = secondLen; i <= n - firstLen; i++) {
            maxRval = max(maxRval, sums[i] - sums[i - secondLen]);
            ans = max(ans, sums[i + firstLen] - sums[i] + maxRval);
        }

        return ans;
    }
};