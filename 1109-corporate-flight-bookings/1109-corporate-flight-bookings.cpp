class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        int s = bookings.size();
        for(int i = 0 ; i < s ; i++){
            ans[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1] < n){
                ans[bookings[i][1]] -= bookings[i][2];
            }
            

        }
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            cnt += ans[i];
           
            ans[i] = cnt;

        }
        return ans;
    }
};