class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int keep = arr[0];
        
        int deleted = -10000; 
        int ans = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            int prevKeep = keep;
            int prevDeleted = deleted;
            
            deleted = max(prevKeep, prevDeleted + arr[i]);
            
            keep = max(arr[i], prevKeep + arr[i]);

            ans = max({ans, keep, deleted});
        }
        
        return ans;
    }
};