class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        
        bool upper = isupper(word[0]);
        
        if (!upper && isupper(word[1])) return false;
        if(upper && !isupper(word[1])) upper = false;
        
        for(int i = 2; i < word.length(); i++) {
            if((bool)isupper(word[i]) != upper) return false;
        }
        
        return true;
    }
};