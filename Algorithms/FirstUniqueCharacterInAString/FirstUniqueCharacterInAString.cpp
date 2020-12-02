class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> v(26, make_pair(0, 0));
        
        for(int i = 0; i < s.length(); i++) {
            if(v[s[i]-'a'].first == 0) {
                v[s[i]-'a'] = make_pair(1, i);
            } else {
                v[s[i]-'a'].first++;
            }
        }
        
        bool foundLetter = false;
        int index = s.length();
        for(size_t i = 0; i < v.size(); i++) {
            if(v[i].first == 1 && v[i].second < index) {
                foundLetter = true;
                index = v[i].second;
            }
        }
        
        if(!foundLetter) return -1;
        
        return index; 
    }
};