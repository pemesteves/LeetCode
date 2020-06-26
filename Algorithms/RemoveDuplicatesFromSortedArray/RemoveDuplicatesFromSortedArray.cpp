class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int lastNum = nums[0];
        int lastPos = -1;
        int length = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                lastNum = nums[i];
                lastPos = i;
                break;
            }
            length++;
        }
        
        if(lastPos == -1)
            return nums.size();
        
        for(int i = lastPos + 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[lastPos] = nums[i];
                lastNum = nums[i];
                lastPos++;
                length++;
            }
        }
        return length;
    }
};