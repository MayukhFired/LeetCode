class Solution {
private:
    bool match(const char* s , const char* p){
        if(*p == '\0'){
            return *s == '\0';
        }

        bool first_match = (*s != '\0' && (*p == *s || *p == '.'));
        if(*(p + 1) == '*'){
            return match(s , p + 2) || (first_match && match(s + 1 , p));
        }
        return first_match && match(s + 1 , p + 1);
    }
public:
    bool isMatch(string s, string p) {
        return match(s.c_str() , p.c_str());
    }
};