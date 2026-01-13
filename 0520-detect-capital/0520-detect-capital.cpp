/*
    Company Tags                : GOOGLE
*/

//Approach-2 (Small and simple)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals = 0;
        
        for(char &ch : word) {
            if(isupper(ch))
                countCapitals++;
        }
        
        if(countCapitals == 0)
            return true;
        
        if(countCapitals == word.length())
            return true;
        
        if(countCapitals == 1 && isupper(word[0]))
            return true;
        
        return false;
    }
};