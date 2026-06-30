class Solution {
public:
    long long minimumSteps(string s) {
        long ans = 0;
        long j = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '0'){
                ans += j;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};