class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int maxi = INT_MIN;
        int maxiInx = 0;
        int mini = INT_MAX;
        int miniInx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxiInx = i;
            }

            if (nums[i] < mini) {
                mini = nums[i];
                miniInx = i;
            }
        }

        cout << mini << " " << maxi;
        int n = nums.size();

        int front = max(maxiInx, miniInx) + 1;

        int back = n - min(maxiInx, miniInx);

        int both = (min(maxiInx, miniInx) + 1) + (n - max(maxiInx, miniInx));

        return min({front, back, both});
    }
};