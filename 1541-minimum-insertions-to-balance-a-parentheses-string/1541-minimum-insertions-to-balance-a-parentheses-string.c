int minInsertions(char* s) {
    int insertions = 0;
    int leftCount = 0;
    int index = 0;

    while(index < strlen(s)){
        char c = s[index];
        if(c == '('){
            leftCount++;
            index++;
        }else{
            if(leftCount > 0){
                leftCount--;
            }else{
                insertions++;
            }
            if(index < strlen(s) - 1 && s[index + 1] == ')'){
                index += 2;
            }else{
                insertions++;
                index++;
            }
        }
    }

    insertions += leftCount * 2;
    return insertions;
}