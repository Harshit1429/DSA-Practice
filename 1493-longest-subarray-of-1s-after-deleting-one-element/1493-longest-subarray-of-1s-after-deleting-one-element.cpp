class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int lastZero = 0;
        int maxOnes = 0;
        int i = 0;
        bool isUsed = false;
        int count = 0;

        while (i < nums.size()) {

            if (nums[i] == 1) {
                count++;
                i++;
            } else {

                if (k != 0) {
                    k--;
                    isUsed = true;
                    lastZero = i;
                    i++;
                } else {
                    maxOnes = max(maxOnes, count);
                    i = lastZero + 1;
                    k = 1;
                    count = 0;
                }
            }
        }
        maxOnes = max(maxOnes, count);

        if (!isUsed) {
            return maxOnes - k;
        }
        return maxOnes;
    }
};