class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        for(int i = 1 ; i <= nums.size() ; i++){
            if(!st.contains(k * i)){
                return k * i;
            }
        }
        return k * (nums.size() + 1);
    }
};