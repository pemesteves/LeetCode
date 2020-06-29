class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        
        int n1 = 1, n2 = 1, result = n1+n2;
        for(int i = 0; i < n-2; i++){
            n1 = n2;
            n2 = result;
            result = n1+n2;
        }
        
        return result;
    }
};