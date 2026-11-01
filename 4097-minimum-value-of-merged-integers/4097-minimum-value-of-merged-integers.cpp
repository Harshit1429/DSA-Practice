class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;

        for (int i = 0; i < nums.size() - 1; i+=2) {
            string sb = "";
            sb += to_string(nums[i]);
            sb += to_string(nums[i + 1]);

            mini = min(mini, stoi(sb));
        }

        return mini;
    }
};