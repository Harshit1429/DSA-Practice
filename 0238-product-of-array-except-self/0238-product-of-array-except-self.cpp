class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size() , 1);
        for(int i = 1 ; i < nums.size(); i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }
        int suffix = 1;
        for(int j = nums.size() - 2 ; j >= 0 ; j--){
            suffix *= nums[j+1];
            prefix[j] *= suffix;
        }
        return prefix;
    }
};