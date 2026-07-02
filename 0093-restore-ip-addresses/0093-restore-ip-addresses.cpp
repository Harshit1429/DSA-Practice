class Solution {
public:
    void check(string &s, int start, vector<string>& ans, string dummy, int count) {
        if(count == 4) {
            if(start == s.length()) {
                dummy.pop_back(); 
                ans.push_back(dummy);
            }
            return;
        }

        string temp = "";

        for(int i = start; i < s.length() && i < start + 3; i++) 
        {
            temp += s[i];

            if(temp.length() > 1 && temp[0] == '0') break;

            int val = stoi(temp);
            if(val > 255) break;

            check(s, i + 1, ans, dummy + temp + ".", count + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12) return {};
        vector<string> ans;

        check(s, 0, ans, "", 0);

        return ans;
    }
};