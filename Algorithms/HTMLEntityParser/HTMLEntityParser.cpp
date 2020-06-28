class Solution {
    string getEntity(string s){
        if(s == "&quot;"){
            return "\"";
        }else if(s == "&apos;"){
            return "\'";
        }else if(s == "&amp;"){
            return "&";
        }else if(s == "&gt;"){
            return ">";
        }else if(s == "&lt;"){
            return "<";
        }else if(s == "&frasl;"){
            return "/";
        }
        return s;
    }
public:
    string entityParser(string text) {
        ostringstream oss;
        for(int i = 0; i < text.length(); i++){
            if(text[i] == '&'){
                bool found = false;
                ostringstream tmp; 
                for(int j = i; j < text.length(); j++){
                    tmp << text[j];
                    if(text[j] == ';'){
                        found = true;
                        break;
                    }
                }
                if(found){
                    string entity = getEntity(tmp.str());
                    if(entity == tmp.str())
                        oss << text[i]; 
                    else{
                        oss << entity;
                        i += tmp.str().length()-1;
                    }
                }else{
                    oss << tmp.str();
                    break;
                }
            }else{
                oss << text[i];
            }
        }
        return oss.str();
    }
};