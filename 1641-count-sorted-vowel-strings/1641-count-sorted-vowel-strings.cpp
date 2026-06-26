

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>dp = {0,1,1,1,1,1};
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<=5;i++)
            {
                dp[i] += dp[i-1];
            }
        }
        return dp[5];
    }
};
