

char * mergeAlternately(char * word1, char * word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int returnsize = len_1 + len_2 + 1;
    char* result = malloc(returnsize *sizeof(char));

    int i = 0 , j = 0 , k = 0;

    while(i < len_1 || j < len_2){
        if(i < len_1){
            result[k++] = word1[i++];
        }

        if(j < len_2){
            result[k++] = word2[j++];
        }
    }
// Another method to solve it 
//    while(i < len_1){
//         result[k++] = word1[i++];
//     }

//     while(j < len_2){
//         result[k++] = word2[j++];
//     }

    result[k] = '\0';

    return result;
}