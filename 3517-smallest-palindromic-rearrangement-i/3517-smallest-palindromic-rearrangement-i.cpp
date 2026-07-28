class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>freq(26,0);

        for(int i = 0 ;i<n ;i++)
        {
            freq[s[i]-'a']++;
        }

        char ch = '9';
        string ans = "";

        for(int i = 0 ;i<26 ;i++)
        {
            char c = i + 'a';
            if(freq[i]>0)
            {
                if(freq[i]%2==1) ch = c;

                ans.append(freq[i]/2,c);
            }
        }

        string revAns = ans;
        reverse(revAns.begin(),revAns.end());

        if(ch!='9') return (ans + ch + revAns);
        else return (ans + revAns); 
    }
};