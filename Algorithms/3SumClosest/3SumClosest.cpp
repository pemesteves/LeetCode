class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long solution = INT_MAX;
        
        for(size_t i = 0; i < nums.size(); i++) {
            for(size_t j = i + 1; j < nums.size(); j++) {
                for(size_t k = j + 1; k < nums.size(); k++) {
                    long sum = nums[i] + nums[j] + nums[k];
                    if(abs(target - solution) > abs(target - sum)) solution = sum;  
                }
            }
        }
        
        return solution;
    }
};