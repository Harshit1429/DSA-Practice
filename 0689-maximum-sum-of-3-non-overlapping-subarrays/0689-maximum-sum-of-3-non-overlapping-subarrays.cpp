#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Compute sums of all valid windows of length k
        int current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        
        std::vector<int> sums;
        sums.push_back(current_sum);
        for (int i = 1; i <= n - k; ++i) {
            current_sum += nums[i + k - 1] - nums[i - 1];
            sums.push_back(current_sum);
        }
        
        int m = sums.size();
        
        // 2. Build left array: index of the max window sum from 0 to i
        std::vector<int> left(m, 0);
        int best_left_idx = 0;
        for (int i = 0; i < m; ++i) {
            if (sums[i] > sums[best_left_idx]) {
                best_left_idx = i;
            }
            left[i] = best_left_idx;
        }
        
        // 3. Build right array: index of the max window sum from i to m-1
        std::vector<int> right(m, 0);
        int best_right_idx = m - 1;
        // Traverse backwards to naturally maintain the lexicographically smallest index on ties
        for (int i = m - 1; i >= 0; --i) {
            if (sums[i] >= sums[best_right_idx]) {
                best_right_idx = i;
            }
            right[i] = best_right_idx;
        }
        
        // 4. Find the best combination by evaluating every possible middle window
        int max_total_sum = -1;
        std::vector<int> ans(3, 0);
        
        for (int j = k; j < m - k; ++j) {
            int l_idx = left[j - k];
            int r_idx = right[j + k];
            int total_sum = sums[l_idx] + sums[j] + sums[r_idx];
            
            if (total_sum > max_total_sum) {
                max_total_sum = total_sum;
                ans[0] = l_idx;
                ans[1] = j;
                ans[2] = r_idx;
            }
        }
        
        return ans;
    }
};
