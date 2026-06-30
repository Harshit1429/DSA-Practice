class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prev = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            prev *= nums[i];
            maxi = max(maxi , prev);
            if(prev == 0){
                prev = 1;
            }
        }
        prev = 1;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            prev *= nums[i];
            maxi = max(maxi , prev);
            if(prev == 0){
                prev = 1;
            }
        }
        return maxi;
    }
};