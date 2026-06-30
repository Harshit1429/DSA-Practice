class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> prefix(nums.size() , 0);
        vector<long> suffix(nums.size() , 0);
        int count = 0;
        prefix[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
         suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2 ; i >= 0 ; i--){
            suffix[i] = nums[i] + suffix[i+1];

        }

        for(int i = 0 ; i < nums.size() - 1; i++){
            if(prefix[i] >= suffix[i+1]){
                count++;
            }
        }
        return count;
    }
};
/*
10 14 6 13
13 3 -1 7  

2 5 6 6
6  4  1  0
*/