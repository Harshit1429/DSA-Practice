class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<pair<int,int>> mp;

        for(int i = 0; i < score.size(); i++){
            mp.push_back({score[i], i});
        }

        sort(mp.begin(), mp.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        });

        vector<string> ans(score.size());

        for(int i = 0; i < mp.size(); i++){

            if(i == 0){
                ans[mp[i].second] = "Gold Medal";
            }
            else if(i == 1){
                ans[mp[i].second] = "Silver Medal";
            }
            else if(i == 2){
                ans[mp[i].second] = "Bronze Medal";
            }
            else{
                ans[mp[i].second] = to_string(i + 1);
            }
        }

        return ans;
    }
};