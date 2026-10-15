class Solution {
public:
    string maskPII(string s) {
        int n = s.length();
        if(isalpha(s[0])){
            string ans = "";
            for(char ch : s){
                ans += tolower(ch);
            }
            int at = ans.find('@');
            string res = "";
            res += ans[0];
            res += "*****";
            res += ans[at - 1];
            res += ans.substr(at);
            return res;
        }else{
            string digit = "";
            for(char ch : s){
                if(isdigit(ch)){
                    digit += ch;
                }
            }
            int cntry = digit.size() - 10;
            string ans = "";
            if(cntry > 0){
                ans += '+';
                for(int i = 0; i < cntry; i++){
                    ans += '*';
                }
                ans += '-';
            }
            ans += "***-***-";
            ans += digit.substr(digit.size() - 4);
            return ans;
        }
    }
};