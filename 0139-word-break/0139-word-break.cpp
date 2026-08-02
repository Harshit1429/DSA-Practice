class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1,false); // dp[i] denotes - can we create s(0,i) from words of wordDict
        dp[0]=true;
        unordered_set<string>st;
        for(auto x:wordDict)st.insert(x);
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                // whether can we create s(j,i) from words of wordDict if we can create s(0,j)
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};