class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int min_len = n + 1;
        string result = "";
        int ones = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == '1'){
                ones++;
            }
            while(ones == k){
                int curr_len = r - l + 1;
                string curr_str = s.substr(l , curr_len);
                if(curr_len < min_len){
                    min_len = curr_len;
                    result = curr_str;
                }else if(curr_len == min_len){
                    if(curr_str < result){
                        result = curr_str;
                    }
                }
                if(s[l] == '1'){
                    ones--;
                }
                l++;
            }
        }
        return result;
    }
};