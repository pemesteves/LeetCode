class Solution {
public:
    int binaryGap(int n) {
        int longestDistance = 0, lastLength = -1, length = 0;
        
        while (n > 0) {
            length += 1;
            if (n % 2 == 0) {
                n /= 2;
                continue;
            }
            
            if (lastLength > -1 && length - lastLength > longestDistance) {
                longestDistance = length - lastLength;
            }
            
            lastLength = length;
            
            n /= 2;
        }
        
        return longestDistance;
    }
};