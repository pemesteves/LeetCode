class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            auto it = freq.find(nums[i]);
            if(it != freq.end()){
                (*it).second++;
                if((*it).second > nums.size()/2)
                    return (*it).first;
            }else{
                freq.insert(make_pair(nums[i], 1));
            }
        }
        
        return nums[0];
    }
};