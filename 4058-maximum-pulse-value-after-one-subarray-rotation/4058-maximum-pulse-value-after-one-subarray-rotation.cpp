#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    long long maxValue(std::vector<int>& nums) {
        int n = nums.size();
        
        // 1. Calculate the base pulse value of the original array
        long long base_pulse = 0;
        for (int i = 0; i < n; ++i) {
            base_pulse += (i % 2 == 0) ? nums[i] : -nums[i];
        }
        
        long long max_gain = 0;
        
        // Lambda to get the B[i] value on the fly: B[i] = -2 * (-1)^i * nums[i]
        auto get_B = [&](int i) -> long long {
            return (i % 2 == 0) ? -2LL * nums[i] : 2LL * nums[i];
        };
        
        // 2. Kadane's on pairs starting at even indices (0, 2, 4...)
        long long current_gain = 0;
        for (int i = 0; i < n - 1; i += 2) {
            long long pair_sum = get_B(i) + get_B(i + 1);
            current_gain = std::max(pair_sum, current_gain + pair_sum);
            max_gain = std::max(max_gain, current_gain);
        }
        
        // 3. Kadane's on pairs starting at odd indices (1, 3, 5...)
        current_gain = 0;
        for (int i = 1; i < n - 1; i += 2) {
            long long pair_sum = get_B(i) + get_B(i + 1);
            current_gain = std::max(pair_sum, current_gain + pair_sum);
            max_gain = std::max(max_gain, current_gain);
        }
        
        return base_pulse + max_gain;
    }
};
