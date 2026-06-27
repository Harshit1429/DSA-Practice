class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0 , idx = 0 , right = nums.size()-1;

        while(idx <= right){

            if(nums[idx] == 0){
                swap(nums[idx] , nums[left]);
                idx++;
                left++;
            }
            else if(nums[idx] == 1){
                idx++;
            }
            else{
                swap(nums[idx] , nums[right]);
                right--;
            }
        }
    }
};