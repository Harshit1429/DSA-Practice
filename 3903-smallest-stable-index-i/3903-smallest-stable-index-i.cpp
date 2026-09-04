class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

         int Prevmaxi = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            Prevmaxi = max(Prevmaxi , nums[i]);
            int mini = findmini(i , nums);
            if(abs(Prevmaxi - mini) <= k){
                return i;
            }
        }
        return -1;
    }
    int findmini(int i ,vector<int>& nums ){
        int mini = INT_MAX;
        for(int num  = i ; num < nums.size() ; num++){
             mini = min(mini , nums[num]);
        }
        return mini;
    }
};