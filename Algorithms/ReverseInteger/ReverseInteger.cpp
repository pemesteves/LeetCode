class Solution {
public:
    int reverse(int x) {
        ostringstream oss;
        oss << x;
        
        string s = oss.str();
        
        int offset = x < 0 ? 1 : 0;
        
    
        oss.str("");
        oss.clear();
        
        if(x<0) oss << "-";
        
        for(int i = s.length()-1; i >= offset; i--){
            oss << s[i];
        }
        
        try{
            return stoi(oss.str());
        }catch(out_of_range e){
            return 0;
        }
    }
};