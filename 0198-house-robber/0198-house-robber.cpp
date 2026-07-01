class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()- 1;
        vector<int> dp(n+1 , -1);
        return recursion(nums, n , dp);
    }
    int recursion(vector<int>& nums , int n , vector<int>& dp){

        if(n == 0){
            return nums[0];
        }

        if(n < 0){
            return 0;
        }

        if(dp[n] != -1) return dp[n];

        int inc = recursion(nums , n - 2 , dp) + nums[n];
        int exc = recursion(nums , n - 1 , dp) + 0;

        dp[n]= max(inc , exc);
        return dp[n];
    }
};