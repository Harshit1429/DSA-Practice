class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        long long mini = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                ans += nums[i];
                mini = min(mini, (long long)nums[i]);
            } else {
                if(i + 1 < n && s[i + 1] == '1') {
                    ans += nums[i];
                   
                    mini = min(mini, (long long)nums[i]);
                    ans -= mini;
                }
                
                mini = INT_MAX;
            }
        }
        return ans;
    }
};