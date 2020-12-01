class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= floor(num / 2.0); i++) {
            if(num % i == 0) {
                sum += i;
            }
        }
        
        return num == sum;
    }
};