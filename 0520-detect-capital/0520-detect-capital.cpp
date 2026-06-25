class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(),count=0,COUNT=0;
        for(int i=1;i<n;i++){
            if(islower(word[i]))count++;
            if(isupper(word[i]))COUNT++;
        }
        if(count==n-1 ||(COUNT==n-1 && isupper(word[0])))return true;
        return false;
    }
};