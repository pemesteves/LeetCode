class Solution {
    void clearMap(unordered_map<char, int> &map, char c){
        for(auto it = map.begin(); it != map.end(); it++){
            (*it).second = 0;
        }
        auto it = map.find(c);
        if(it == map.end())
            map.insert(make_pair(c, 1));
        else
            (*it).second = 1;
    }
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substr_char_freq;
        
        if(s.length() == 0)
            return 0;
        
        int max_length = 1;
        for(int i = 0; i < s.length(); i++){
            int j;
            clearMap(substr_char_freq, s[i]);
            for(j = i+1; j < s.length(); j++){
                auto it = substr_char_freq.find(s[j]);
                if(it == substr_char_freq.end()){
                    substr_char_freq.insert(make_pair(s[j], 1));
                }else{
                    (*it).second++;
                    if((*it).second > 1){
                        break;
                    }
                }
            }
            
            if(j-i > max_length)
                max_length = j-i;
            
            if(j+1 == s.length())
                break;
        }
        
        return max_length;
    }
};