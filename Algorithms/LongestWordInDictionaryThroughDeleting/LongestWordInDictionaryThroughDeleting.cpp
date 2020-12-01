class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for(size_t i = 0; i < d.size(); i++) {
            if(d[i].length() < result.length()) continue;
            if(d[i].length() == result.length() && lexicographical_compare(result.begin(), result.end(), d[i].begin(), d[i].end())) continue; 

            int j = 0, k = 0;
            for(; j < d[i].length(), k < s.length();) {
                if(d[i][j] == s[k]) {
                    j++; k++;
                } else {
                    k++;
                }
            }
            if(j == d[i].length()) {
                result = d[i];
            }
        }
        
        return result;
    }
};