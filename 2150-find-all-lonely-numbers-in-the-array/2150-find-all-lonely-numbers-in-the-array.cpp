class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int , int> mp;

        for(int num : nums){
            mp[num]++;
        }
        for(int num : nums){

            if(mp.find(num) != mp.end() && mp[num] == 1 && mp.find(num-1) == mp.end() && mp.find(num+1) == mp.end()){
                ans.push_back(num);
            }
            
        }
        return ans;
    }
};