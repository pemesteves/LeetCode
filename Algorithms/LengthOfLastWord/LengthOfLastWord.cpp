class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ' ' && l != 0)
                break;
            else if(s[i] != ' ')
                l++;
        }
        
        return l;
    }
};