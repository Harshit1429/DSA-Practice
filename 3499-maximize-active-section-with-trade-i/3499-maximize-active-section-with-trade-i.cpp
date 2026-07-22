class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = 0; 
        int n = s.length(); 
        for(int i = 0; i < n; i++) if(s[i] == '1') cnt1++; 
        // Now what
        int prevZeros = -1, ans = 0; // equals to no of oones 
        int i = 0; 
        while(i < n) {
            int j = i; 
            while(j < n && s[j] == s[i]) j++; 
            int len = j - i; 

            if(s[i] == '0') {
                // this block is of zero's 
                if(prevZeros != -1) ans = max(ans, prevZeros + len ); // only when we have block of zero's in left. 
                prevZeros = len; 
            }
            i = j; 
        }
        return cnt1 + ans; 
    }
};