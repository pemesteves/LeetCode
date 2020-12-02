class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> v(nums.size()+1, false);
        
        for(size_t i = 0; i < nums.size(); i++) {
            v[nums[i]] = true;    
        }
        
        for(size_t i = 0; i < v.size(); i++) {
            if(!v[i]) return i;
        }
        
        return -1;
    }
};