class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        
        string s = "";
        for(int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            for(size_t j = 1; j < strs.size(); j++){
                if(j >= strs.size()) return s;
                if(strs[j][i] != c) return s;
            }
            s += c;
        }
        
        return s;
    }
};