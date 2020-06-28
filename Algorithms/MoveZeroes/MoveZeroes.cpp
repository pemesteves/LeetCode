    class Solution {
    public:
        void moveZeroes(vector<int>& nums) { 
            queue<int> zeroPos;

            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] != 0){
                    if(!zeroPos.empty()){
                        nums[zeroPos.front()] = nums[i];
                        nums[i] = 0;
                        zeroPos.pop();
                        zeroPos.push(i);
                    }
                }else{
                    zeroPos.push(i);
                }
            }
        }
    };