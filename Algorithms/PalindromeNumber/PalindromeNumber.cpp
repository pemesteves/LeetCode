class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        ostringstream oss;
        oss << x;
        string s = oss.str();
        for(int i = 0, j = s.length()-1; i < j; i++, j--){
            if(s[i] != s[j])
                return false;
        }
        
        return true;
    }
};