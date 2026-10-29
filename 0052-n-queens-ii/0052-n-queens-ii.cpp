#include <vector>

class Solution {
private:
    int n = 0;
    int ans = 0;
    std::vector<bool> col;
    std::vector<bool> dail1;
    std::vector<bool> dail2;

    void solve(int r) {
        if (r == n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1;
            int d2 = r + c; 
            if (col[c] || dail1[d1] || dail2[d2]) {
                continue;
            }
            place(r, c);
            solve(r + 1);
            remove(r, c);
        }
    }

    void place(int r, int c) {
        col[c] = true;
        dail1[r - c + n - 1] = true;
        dail2[r + c] = true;
    }

    void remove(int r, int c) {
        col[c] = false;
        dail1[r - c + n - 1] = false;
        dail2[r + c] = false;
    }

public:
    int totalNQueens(int n) {
        this->n = n;
        this->ans = 0; // Reset for multiple test cases on LeetCode
        col = std::vector<bool>(n, false);
        dail1 = std::vector<bool>(2 * n - 1, false);
        dail2 = std::vector<bool>(2 * n - 1, false);
        solve(0);
        return ans;
    }
};