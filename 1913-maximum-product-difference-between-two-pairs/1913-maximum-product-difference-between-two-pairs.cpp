class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int one = nums[0];
        int two = nums[1];
        int three = nums[nums.size()-2];
        int four = nums[nums.size()-1];

        return (four * three) - (two * one);
    }
};