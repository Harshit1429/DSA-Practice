class Solution {
public:
    int n;
    int findnext(vector<pair<int,pair<int,int>>> &nums,int tar){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid].first>=tar){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int f(vector<pair<int,pair<int,int>>> &nums,int i,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake=f(nums,i+1,dp);
        int nextind=findnext(nums,nums[i].second.first);
        int take=nums[i].second.second+f(nums,nextind,dp);
        return dp[i] = max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=endTime.size();
        vector<pair<int,pair<int,int>>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        return f(nums,0,dp);
    }
};
