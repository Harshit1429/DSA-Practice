class Solution {
public:
    bool checkString(string s) {
        bool isAfter = false;
          
          if(s[0] == 'b' && s[1] == 'a') return false;

        for(int i = 0 ; i < s.length(); i++){
           
           if(s[i] == 'a' && isAfter){
            return false;
           }
           else if(s[i] == 'b'){
            isAfter = true;
           }
        
        } 
        return true;
    }
};