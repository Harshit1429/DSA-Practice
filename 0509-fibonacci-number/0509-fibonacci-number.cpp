class Solution {
public:
    int recursive(int n , vector<int>& dp){
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1) return dp[n];

        dp[n] = recursive(n - 1 , dp) + recursive(n - 2 , dp);
        return dp[n];
    }
    int fib(int n) {
       vector<int> dp(n+1 , -1);
       return recursive(n , dp);
    }
};