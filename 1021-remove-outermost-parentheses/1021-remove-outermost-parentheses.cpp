class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int x =0;
        for(auto i:s){
            if(i=='(')x++;
            if(x>1)ans+=i;
            if(i==')')x--;
        }
        return ans;
    }
};