class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> m;
        m.insert(nums1.begin(), nums1.end());
        m.insert(nums2.begin(), nums2.end());
        
        if(m.size() == 0) return 0;
        
        size_t i = 0;
        bool isEven = m.size() % 2 == 0;
        size_t mid = m.size() / 2;
        
        for(auto it = m.begin(); it != m.end(); it++) {
            if(isEven && i == mid - 1) {
                auto it1 = it;
                it++;
                return ((double)(*it) + (double)(*it1)) / 2.0;
            }else if(!isEven && i == mid) {
                return *it;
            }
            i++;
        }
        
        return 0;
    }
};