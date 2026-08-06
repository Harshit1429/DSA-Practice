class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> st;
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]);
            st.insert(nums[i]);
        }
        
        vector<int> ans;

        for(int i = mini ; i <= maxi ; i++){
            if(!st.contains(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};