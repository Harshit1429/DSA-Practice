class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char , int> mp;

        int left = 0 , right = 0;
        int maxLenght = 0 ;

        while(left <= right && right < s.length()){

            if(mp.find(s[right]) != mp.end()){
                mp.erase(s[left]);
                left++;
            }
            else{
                mp[s[right]];
                maxLenght = max(maxLenght , right - left +1);
                right++;
            }
        }
      return maxLenght;  
    }
};