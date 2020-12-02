class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> um;
        
        for(size_t i = 0; i < nums1.size(); i++) {
            um.insert(nums1[i]);    
        }
        
        vector<int> v;
        for(size_t i = 0; i < nums2.size(); i++) {
            auto it = um.find(nums2[i]);
            if(it != um.end()) {
                um.erase(it);
                v.push_back(nums2[i]);
            }
        }
        
        return v;
    }
};