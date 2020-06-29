class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> positions;
        int length = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                positions.push(i);
            }else{
                length++;
                if(!positions.empty()){
                    int p = positions.front();
                    positions.pop();
                    nums[p] = nums[i];
                    nums[i] = val;
                    positions.push(i);
                }
            }
        }
        return length;
    }
};
