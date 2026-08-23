class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";

        // Convert every character into
        // its 8-bit ASCII binary representation
        for (char c : s) {
            int ascii = int(c);

            string bin = bitset<8>(ascii).to_string();

            binary += bin;
        }

        // Two-pointer palindrome check
        int i = 0;
        int j = binary.size() - 1;

        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};