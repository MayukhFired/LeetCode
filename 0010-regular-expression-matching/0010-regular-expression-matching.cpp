class Solution {
private:
    // bool match(const char* s , const char* p){
    //     if(*p == '\0'){
    //         return *s == '\0';
    //     }

    //     bool first_match = (*s != '\0' && (*p == *s || *p == '.'));
    //     if(*(p + 1) == '*'){
    //         return match(s , p + 2) || (first_match && match(s + 1 , p));
    //     }
    //     return first_match && match(s + 1 , p + 1);
    // }

    bool dp(int i , int j , const string& s , const string& p , vector<vector<int>>& memo){
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        bool ans;
        if(j == p.length()){
            ans = (i == s.length());
        }else{
            bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
            if(j + 1 < p.length() && p[j + 1] == '*'){
                ans = dp(i , j + 2 , s , p , memo) || (first_match && dp(i + 1 , j , s , p , memo));
            }else{
                ans = first_match && dp(i + 1 , j + 1 , s , p , memo);
            }
        }
        return memo[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        // return match(s.c_str() , p.c_str());
        int n = s.length();
        int m = p.length();

        vector<vector<int>> memo(n + 1 , vector<int>(m + 1 , -1));
        return dp(0 , 0 , s , p , memo);
    }
};