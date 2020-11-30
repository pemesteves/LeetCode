class Solution {
    string getLongestPalindrome(vector<pair<int, int>> pairs, string s, int long_len) {
        string result = "";
        for(size_t i = 0; i < pairs.size(); i++) {
            int len = pairs[i].second - pairs[i].first + 1;
            if(len < result.length() || len < long_len) continue;
            
            if(len == 2) {
                result = s.substr(pairs[i].first, 2);
                continue;
            }
            
            bool isPalindrome = true;
            for(int j = pairs[i].first+1, k = pairs[i].second-1; j < k; j++, k--) {
                if(s[j] != s[k]) {
                    isPalindrome = false;
                    break;
                }
            }
            if(isPalindrome) result = s.substr(pairs[i].first, len);
        }
        
        return result;
    }
    
    vector<pair<int, int>> getPairs(vector<int> v) {
        vector<pair<int, int>> pairs;
        for(size_t i = 0; i < v.size(); i++) {
            for(size_t j = i + 1; j < v.size(); j++) {
                pairs.push_back(make_pair(v[i],v[j]));
            }
        }
        return pairs;
    }
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        bool found_rep = false;
        unordered_map<char, vector<int>> char_pos;
        for(int i = 0; i < s.length(); i++) {
            auto it = char_pos.find(s[i]);
            if(it == char_pos.end()) {
                char_pos.insert(make_pair(s[i], vector<int>(1, i)));
            }else {
                found_rep = true;
                (*it).second.push_back(i);
            }
        }
        
        if(!found_rep) return string(1, s[0]);
        
        string substr = "";
        for(auto it = char_pos.begin(); it != char_pos.end(); it++) {
            if((*it).second.size() == 1 && substr.length() < 1) {
                substr = (*it).first;
                continue;
            }
            
            vector<pair<int, int>> pairs = getPairs((*it).second);
            string long_pal = getLongestPalindrome(pairs, s, substr.length());
            substr = long_pal.length() > substr.length() ? long_pal : substr;
        }
        
        return substr;
    }
};