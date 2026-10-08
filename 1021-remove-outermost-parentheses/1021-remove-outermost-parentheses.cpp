class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string res;
        int level = 0;

        for(char curr : s){
            if(curr == ')'){
                level--;
            }
            if(level > 0){
                res.push_back(curr);
            }
            if(curr == '('){
                level++;
            }
        }
        return res;
    }
};