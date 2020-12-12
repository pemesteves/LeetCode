class Solution {
    int getLetterValue(char c) {
        return c - 'A' + 1;
    }
public:
    int titleToNumber(string s) {
        int result = 0; 
        long n = 1;
        for(int i = s.length() - 1; i >= 0; i--, n *= 26) {
            result += getLetterValue(s[i]) * n;
        }
        
        return result;
    }
};
