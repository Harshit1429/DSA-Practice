class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piviot = -1;

        for(int i = nums.size() - 2 ; i >=0 ; i--){
            if(nums[i+1] > nums[i]){
                piviot = i;
                break;
            }
        }
        if(piviot == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        for(int i = nums.size() -1  ; i > piviot ; i--){
             if(nums[i] > nums[piviot]){
                swap(nums[i] , nums[piviot]);
                break;
             }
        }
        int l = piviot +1 , r = nums.size()-1;
        while(l < r){
            swap(nums[l++] , nums[r--]);
        }
        
    }
};