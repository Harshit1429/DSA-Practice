#include <string>
#include <string_view>

class Solution {
public:
    int longestDecomposition(std::string text) {
        if (text.empty()) return 0;
        
        std::string_view sv(text);
        int left = 0, right = sv.length();
        int low = left + 1, high = right - 1;
        int count = 0;
        
        while (low <= high) {
            std::string_view sl = sv.substr(left, low - left);
            std::string_view sr = sv.substr(high, right - high);
            
            if (sl == sr) {
                count += 2;
                left = low;
                right = high;
            }
            
            low++;
            high--;
        }
        
        if (left < right) {
            count += 1;
        }
        
        return count;
    }
};