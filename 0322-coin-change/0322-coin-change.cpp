class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1 , -1);
        int result = helper(coins , amount, ans);

        if(result != INT_MAX){
            return result;
        }
        return -1;
    }
    int helper(vector<int>& coins, int amount,vector<int>& ans){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        if(ans[amount] != -1) return ans[amount];

        int mini = INT_MAX;

        for(int i = 0 ; i < coins.size() ; i++){
          
         int current = helper(coins , amount - coins[i],ans);

          if(current != INT_MAX){
            mini = min(mini , 1+current);
          }
        }
       return ans[amount] = mini;
    }
};