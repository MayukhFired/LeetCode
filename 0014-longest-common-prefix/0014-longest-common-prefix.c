// char* longestCommonPrefix(char** strs, int strsSize) {
//     if(strs == NULL || strsSize == 0){
//         char* empty = (char*)malloc(1);
//         empty[0] = '\0';
//         return empty;
//     }

//     int min_len = strlen(strs[0]);
//     char* compare = (char*)malloc(128* sizeof(char));


//     for(int i = 1; i < strsSize; i++){
//         int j = 0;
//         while(j < min_len && strs[0][j] == strs[i][j]){
//             j++;
//         }

//         min_len = j;
//     }

//     for(int i = 0; i < min_len; i++){
//         compare[i] = strs[0][i];
//     }
//     compare[min_len] = '\0';
//     return compare;

// }
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";

    for (int i = 0; strs[0][i] != '\0'; i++) {
        char ch = strs[0][i];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != ch || strs[j][i] == '\0') {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}