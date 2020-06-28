class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i = digits.size() - 1; i >= 0; i--){
            digits[i]++;
            if(digits[i] > 9){
                digits[i] -= 10;
            }else
                break;
        }
        if(i == -1){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
