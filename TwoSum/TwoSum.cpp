class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<unsigned, int> numbers;
        
        vector<int> solution;
        for(unsigned i = 0; i < nums.size(); i++){
            numbers.insert(make_pair(nums[i], i));
        }
        
        for(unsigned i = 0; i < nums.size(); i++){
            auto range = numbers.equal_range(target-nums[i]);
            
            for(auto it = range.first; it != range.second; it++){
                if((*it).second != i){
                    solution.push_back(i);
                    solution.push_back((*it).second);
                    return solution;
                }   
            }
        }
        
        return solution;
    }
};