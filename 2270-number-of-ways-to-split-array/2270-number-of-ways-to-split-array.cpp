class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;

        for (int x : nums)
            total += x;

        long long left = 0;
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];

            if (left >= total - left)
                ans++;
        }

        return ans;
    }
};