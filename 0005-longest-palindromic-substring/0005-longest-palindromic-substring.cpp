class Solution {
public:
    pair<int , int> solve(const string& s , int i , int j){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        return {i + 1, j - i - 1};
    }
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        int len = s.length();
        int max_len = 0;
        int start = 0;
        for(int i = 0; i < len; i++){
            auto[start1 , len1] = solve(s , i , i);
            if(len1 > max_len){
                max_len = len1;
                start = start1;
            }

            auto[start2 , len2] = solve(s , i , i + 1);
            if(len2 > max_len){
                max_len = len2;
                start = start2;
            }
        }

        return s.substr(start , max_len);
    }
};