class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> idx;
        string res;

        for(char curr_char : s){
            if(curr_char == '('){
                idx.push(res.length());
            }else if(curr_char == ')'){
                int start = idx.top();
                idx.pop();
                reverse(res.begin() + start , res.end());
            }else{
                res += curr_char;
            }
        }
        return res;
    }
};