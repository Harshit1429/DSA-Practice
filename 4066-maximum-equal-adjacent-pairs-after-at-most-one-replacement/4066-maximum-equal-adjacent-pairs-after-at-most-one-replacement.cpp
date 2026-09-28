class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        int n = nums.size();

        int count = 0; // count of elements which are already equal
        int extra = 0; // count of extra elements we are gonna convert

        map<pair<int,int>,int> mpp;

        for( int i = 0 ; i < n-1 ; i++ ){

            // This pair is already equal
            if( nums[i] == nums[i+1] ) count++;

            // Store the pair independent of its direction
            else {

                int x = min(nums[i],nums[i+1]);
                int y = max(nums[i],nums[i+1]);

                // Count how many times this pair occurs
                mpp[{x,y}]++;
                extra = max(extra,mpp[{x,y}]);

            }
        }

        return count+extra ;
        
    }
};