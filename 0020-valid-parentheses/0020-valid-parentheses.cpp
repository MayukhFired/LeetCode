class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0){
            return false;
        }
        stack<char> st;

        for(char current : s){
            if(current == '(' || current == '{' || current == '['){
                st.push(current);
            }else{
                if(st.empty()){
                    return false;
                }
                char topChar = st.top();
                if((current == ')' && topChar == '(') || (current == '}' && topChar == '{') || (current == ']' && topChar == '[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};