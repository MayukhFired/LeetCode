

// char * mergeAlternately(char * word1, char * word2){
//     int len_1 = strlen(word1);
//     int len_2 = strlen(word2);
//     int returnsize = len_1 + len_2 + 1;
//     char* result = malloc(returnsize *sizeof(char));

//     int i = 0 , j = 0 , k = 0;

//     while(i < len_1 || j < len_2){
//         if(i < len_1){
//             result[k++] = word1[i++];
//         }

//         if(j < len_2){
//             result[k++] = word2[j++];
//         }
//     }
// // Another method to solve it 
// //    while(i < len_1){
// //         result[k++] = word1[i++];
// //     }

// //     while(j < len_2){
// //         result[k++] = word2[j++];
// //     }

//     result[k] = '\0';

//     return result;
// }


char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int returnSize = len1+len2;
    char* result = malloc((returnSize+1)*sizeof(char));
    int i=0,j=0,k=0;
    while(i<len1 || j<len2)
    {
        if(i<len1)
        {
            result[k++] = word1[i++];
        }
        if(j<len2)
        {
            result[k++] = word2[j++];
        }
    }
    result[k] = '\0';
    return result;

}