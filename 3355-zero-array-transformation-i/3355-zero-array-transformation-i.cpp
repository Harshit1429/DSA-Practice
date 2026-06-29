class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for(auto &q : queries) {

            int l = q[0];
            int r = q[1];

            diff[l]++;

            if(r + 1 < n)
                diff[r + 1]--;
        }

        int coverage = 0;

        for(int i = 0; i < n; i++) {

            coverage += diff[i];

            if(coverage < nums[i])
                return false;
        }

        return true;
    }
};