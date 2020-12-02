class Solution {
    int getInt(char c) {
        return c - '0';
    }
public:
    string addStrings(string num1, string num2) {
        if(num1.length() == 0 && num2.length() == 0) return "0";
        
        int i = num1.length()-1, j = num2.length()-1;
        int c = 0;
        ostringstream oss;
        for(; i >= 0 && j >= 0; i--, j--) {
            int tmp = getInt(num1[i]) + getInt(num2[j]) + c;
            if(tmp >= 10) {
                tmp -= 10;
                oss << tmp;
                c = 1;
            } else {
                oss << tmp;
                c = 0;
            }
        }
        
        // If num1 is longer than num2
        for(; i >= 0; i--) {
            int tmp = getInt(num1[i]) + c; 
            if(tmp >= 10) {
                tmp -= 10;
                oss << tmp;
                c = 1;
            } else {
                oss << tmp;
                c = 0;
            }
        }
        
        // If num2 is longer than num1
        for(; j >= 0; j--) {
            int tmp = getInt(num2[j]) + c; 
            if(tmp >= 10) {
                tmp -= 10;
                oss << tmp;
                c = 1;
            } else {
                oss << tmp;
                c = 0;
            }
        }
        
        if(c != 0) oss << c;
        
        string s = oss.str();
        reverse(s.begin(), s.end());
        return s;
    }
};