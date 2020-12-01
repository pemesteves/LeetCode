class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<int> n(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(size_t i = 0; i < nums.size(); i++) {
            m.insert(make_pair(nums[i], (int)i));
        }
        
        vector<string> s(nums.size(), "");
        while(!n.empty()){
            int num = n.top();
            n.pop();
            
            string pos;
            switch(nums.size() - n.size()) {
                case 1: 
                    pos = "Gold Medal";
                    break;
                case 2:
                    pos = "Silver Medal";
                    break;
                case 3:
                    pos = "Bronze Medal";
                    break;
                default:
                    pos = to_string(nums.size() - n.size());
                    break;
            }
            
            s[m[num]] = pos;
        }
        
        return s;
    }
};