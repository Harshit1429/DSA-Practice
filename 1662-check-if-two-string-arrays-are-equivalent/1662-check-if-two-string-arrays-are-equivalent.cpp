class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        for(string s : word1){
            s1 += s;
        }  
         for(string s : word2){
            s2 += s;
        }  
        // sort(s1.begin() , s1.end());
        // sort(s2.begin() , s2.end());

        return s1 == s2;
    }
};