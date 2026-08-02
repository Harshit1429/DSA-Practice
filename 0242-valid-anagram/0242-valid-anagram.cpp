class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }
        
        for(int i = 0 ; i < t.length() ; i++){

            char target = t[i];

            size_t pos = s.find(target);

            if(s.find(target) == string::npos){
                return false;
            }
            s.erase(pos,1);
            
        }
        return true;
    }
};