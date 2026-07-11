class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        for(int i = 1 ; i <= nums.size() ; i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }
        return nums.size()+1;
    }
};