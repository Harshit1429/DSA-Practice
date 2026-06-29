class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n , 0);

        for(int i = 0 ; i < bookings.size() ; i++){
            add(bookings[i][0] , bookings[i][1] ,bookings[i][2] , ans);
        }
        return ans;
    }
    void add(int l , int r ,int val , vector<int>& ans){
        for(int i = l ; i <= r ; i++){
            ans[i-1] += val;
        }
    }
};