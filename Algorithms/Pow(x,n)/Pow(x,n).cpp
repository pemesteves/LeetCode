class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x == 0.0)
            return 0;
        if(x == 1.0)
            return 1;
        if(x == -1.0){
            if(n % 2 == 0)
                return 1;
            return -1;
        }
        if(n <= INT_MIN)
            return 0;
        if(n >= INT_MAX)
            return 0;
            
        double result = x;
        for(int i = 1; i < abs(n); i++){
            result *= x;
        }
        
        if(n < 0){
            result = 1.0 / result;
        }
        
        return result;
    }
};