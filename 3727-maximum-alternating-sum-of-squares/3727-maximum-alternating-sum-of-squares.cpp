class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            long  sqr = (long long)nums[i] * nums[i];
            sq.push_back(sqr);
        }
        sort(sq.begin(), sq.end());
        int left = 0 , right = nums.size()-1;
       while(left <= right){
        if(left == right){
            ans += sq[left];
        }
            ans += sq[right] - sq[left];
            right--;
            left++;
           
       }
        
        return ans;
    }
};
