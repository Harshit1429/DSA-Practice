class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        vector<int> prefixMini(nums.size(),0);
        int mini = INT_MAX;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
                mini = min(mini , nums[i]);
                prefixMini[i] = mini; 
        }
        

         int Prevmaxi = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            Prevmaxi = max(Prevmaxi , nums[i]);
           // int mini = findmini(i , nums);
            if(abs(Prevmaxi - prefixMini[i]) <= k){
                return i;
            }
        }
        return -1;
    }
    // int findmini(int i ,vector<int>& nums ){
    //     int mini = INT_MAX;
    //     for(int num  = i ; num < nums.size() ; num++){
    //          mini = min(mini , nums[num]);
    //     }
    //     return mini;
    // }
};