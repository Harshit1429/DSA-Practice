class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, mult = 1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                mult *= 2;
            } else {
                mult /= 2;
                if (i > 0 && s[i - 1] == '(') {
                    score += mult;
                }
            }
        }
        return score;
    }
};
