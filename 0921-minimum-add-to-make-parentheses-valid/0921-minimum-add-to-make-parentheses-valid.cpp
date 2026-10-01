class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;
        int minAdds = 0;
        for(char curr : s){
            if(curr == '('){
                openBrackets++;
            }else{
                openBrackets > 0 ? openBrackets-- : minAdds++;
            }
        }
        return openBrackets + minAdds;
    }
};