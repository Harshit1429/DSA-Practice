class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        int plus_pos1 = num1.find('+');
        int plus_pos2 = num2.find('+');

       int real1 = stoi(num1.substr(0, plus_pos1));
        int real2 = stoi(num2.substr(0, plus_pos2));
        int img1 = stoi(num1.substr(plus_pos1 + 1));
        int img2 = stoi(num2.substr(plus_pos2 + 1));

        int real_sum = real1 * real2 - img1 * img2;
        int img_sum = real1 * img2 + real2 * img1;

        string ans = to_string(real_sum);
        ans += '+';
        ans += to_string(img_sum);
        ans += 'i';

        return ans;
    }
};