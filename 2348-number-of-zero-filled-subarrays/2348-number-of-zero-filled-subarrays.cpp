class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long ans = 0 , stk = 0;

        for(int n : nums){
            if(n == 0){
                stk++;
                ans += stk;
            }
            else{
                stk = 0;
            }
        }
        return ans;
    }
};