class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        while(mp.size() != 0){
            vector<int> temp;

            for(auto it = mp.begin(); it != mp.end(); ){
                temp.push_back(it->first);
                it->second--;

                if(it->second == 0){
                    it = mp.erase(it);
                }
                else{
                    ++it;
                }
            }

            sort(temp.begin(), temp.end());

            for(int i = 0; i < temp.size(); i++){
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};