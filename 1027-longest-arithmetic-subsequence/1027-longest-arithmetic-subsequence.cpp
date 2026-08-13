class Solution {
public:

    int n;

    int solve(int i, int diff, vector<int>& nums) {

        if(i < 0) return 0;

        int req = nums[i] - diff;

        int cnt = 0;

        for(int k = i - 1; k >= 0; k--) {

            if(nums[k] == req) {

                cnt++;

                req = nums[k] - diff;
            }
        }

        return cnt;
    }

    int longestArithSeqLength(vector<int>& nums) {

        n = nums.size();

        if(n <= 2) return n;

        int ans = 2;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int diff = nums[j] - nums[i];

                ans = max(ans, 2 + solve(i, diff, nums));
            }
        }

        return ans;
    }
};