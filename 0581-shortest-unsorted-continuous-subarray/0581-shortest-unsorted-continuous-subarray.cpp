class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        int first = -1;
        int last = -1;

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (nums[i] < maxi) {
                last = i;
            }

            maxi = max(maxi, nums[i]);
        }

        int mini = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] > mini) {
                first = i;
            }

            mini = min(mini, nums[i]);
        }

        if (first == -1) {
            return 0;
        }

        return last - first + 1;
    }
};