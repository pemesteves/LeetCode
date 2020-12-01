class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        
        int i = 0, j = 1;
        for(int k = 2; k <= N; k++) {
            int tmp = i + j;
            i = j;
            j = tmp;
        }
        
        return j;
    }
};