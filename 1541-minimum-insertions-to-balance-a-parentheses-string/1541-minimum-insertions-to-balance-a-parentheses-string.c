int minInsertions(char* s) {
    // 1--------------------------------------------------------------------1
    // int insertions = 0;
    // int leftCount = 0;
    // int index = 0;

    // while(index < strlen(s)){
    //     char c = s[index];
    //     if(c == '('){
    //         leftCount++;
    //         index++;
    //     }else{
    //         if(leftCount > 0){
    //             leftCount--;
    //         }else{
    //             insertions++;
    //         }
    //         if(index < strlen(s) - 1 && s[index + 1] == ')'){
    //             index += 2;
    //         }else{
    //             insertions++;
    //             index++;
    //         }
    //     }
    // }

    // insertions += leftCount * 2;
    // return insertions;
    // 1---------------------------------------------------------------------------1

    int insert = 0;
    int count = 0;

    while(*s != '\0'){
        if(*s == '('){
            count += 2;
            if(count & 1){
                insert++;
                count--;
            }
        }else{
            if(count == 0){
                insert++;
                count++;
            }else{
                count--;
            }
        }
        s++;
    }

    return count + insert;
}