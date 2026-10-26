class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int SumValleys = 0 , SumPeaks = 0;

        for(int i = 1 ; i < nums.size() - 1 ; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                SumValleys += nums[i];
            }
            if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1]){
                SumPeaks += nums[i];
            }
        }
        return SumValleys - SumPeaks;
    }
};