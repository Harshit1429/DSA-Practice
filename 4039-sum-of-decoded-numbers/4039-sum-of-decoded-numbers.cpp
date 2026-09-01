class Solution {
public:
    // Modulo value to prevent overflow and keep numbers manageable.
    const long long M = 1e9 + 7;

    // Calculates (x^y) % M using Binary Exponentiation.
    //
    // Instead of multiplying x, y times:
    //
    // x^y
    //
    // we repeatedly square x and divide y by 2.
    //
    // Time Complexity: O(log y)
    long long power(long long x, long long y) {
        long long ans = 1;

        // We only need x modulo M.
        x %= M;

        while (y) {

            // If y is odd, multiply the current answer by x.
            if (y % 2) {
                ans = (ans * x) % M;
            }

            // Square x for the next bit of y.
            x = (x * x) % M;

            // Divide exponent by 2.
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();

        // Stores the final sum modulo M.
        long long res = 0;

        for (int i = 0; i < n; i++) {

            // Last digit tells us how many digits belong to y.
            long long w = nums[i] % 10;

            // Remove the last digit.
            // Now d contains the digits of x and y.
            long long d = nums[i] / 10;

            // Find the number of digits in d.
            int len = 0;
            long long temp = d;

            while (temp > 0) {
                len++;
                temp /= 10;
            }

            // Create 10^(len-w).
            //
            // This allows us to separate x and y.
            long long divisor = 1;

            for (int k = 0; k < len - w; k++) {
                divisor *= 10;
            }

            // Extract x (the left part).
            long long x = d / divisor;

            // Extract y (the right part).
            long long y = d % divisor;

            // Calculate x^y and add it to the result.
            res = (res + power(x, y)) % M;
        }

        return (int)res;
    }
};