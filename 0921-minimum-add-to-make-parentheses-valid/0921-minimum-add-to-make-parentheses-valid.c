int minAddToMakeValid(char* s) {
    int openBrackets = 0;
    int minAdds = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '('){
            openBrackets++;
        }else{
            openBrackets > 0 ? openBrackets-- : minAdds++;
        }
    }
    return minAdds + openBrackets;
}