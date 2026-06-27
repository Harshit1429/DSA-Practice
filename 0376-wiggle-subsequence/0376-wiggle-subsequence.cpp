class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diff;
        if(nums.size() == 1) return 1;
        
        for(int i = 0 ; i < nums.size()-1 ; i++){
            diff.push_back(nums[i+1] - nums[i]);
        }

        bool sign = false;
        int ans = 0;

        // if(diff[0] < 0)
        //     sign = 0;
        // else 
        //     sign = 1;
        for(int n : diff){
             if(n == 0){
                continue;
            }
            else{
            sign = n < 0 ? false : true;
            break;
            }
        }
        for(int n : diff){
            if(sign && n > 0){
               ans++;
               sign = 0;
            }
            else if(!sign && n < 0 ){
                ans++;
                sign = 1;
            }

        }

        return ans+1;
    }
};