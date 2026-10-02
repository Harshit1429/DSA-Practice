class Solution {
public:
    bool isplaindrome(long long i,long long j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool part(int i ,int parts ,string &s,vector<vector<int>>&dp){
        if(i >= s.length())
            return false;
        if(parts==2){
            return dp[i][parts]=isplaindrome(i,s.length()-1,s);
        }
        if(dp[i][parts]!=-1) return dp[i][parts];
        for(int j=i;j<s.length()-1;j++){
            if(isplaindrome(i,j,s)){
                if(part(j+1,parts+1,s,dp)){
                    return dp[i][parts]=1;
                }
            }
        }
        return dp[i][parts]=0;

    }
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return part(0,0,s,dp);

    }
};