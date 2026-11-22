class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> le(n, -1);
        le[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) le[i] = le[i-1];
            else le[i] = i;
        }
        
        vector<int> re(n, -1);
        re[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == nums[i+1]) re[i] = re[i+1];
            else re[i] = i;
        }
        
        ll res = LLONG_MAX;
        for(int i = 1; i < n-1; i = re[i] + 1){
            ll cost = 0;
            cost += 1LL * (le[i]) * nums[i];  
            cost += 1LL * (n-1 - re[i]) * nums[i];
            
            res = min(cost, res);
        }
        return res;
    }
};