/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const char* phone_map[] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

void backtrack(const char* digits , int index , char* current , char** result , int* returnSize){
    if(digits[index] == '\0'){
        result[*returnSize] = malloc((index + 1) *sizeof(char));
        strcpy(result[*returnSize] , current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = phone_map[digit];

    for(int i = 0; letters[i] != '\0'; i++){
        current[index] = letters[i];
        current[index + 1] = '\0';
        backtrack(digits , index + 1 , current , result , returnSize);

    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if(len == 0){
        return NULL;
    }

    int total_combinations = 1;
    for(int i = 0; i < len; i++){
        int digit = digits[i] - '0';
        if(digit == 7 || digit == 9){
            total_combinations *= 4;
        }else{
            total_combinations *= 3;
        }
    }

    char** result = malloc(total_combinations * sizeof(char*));
    char* current = malloc((len + 1) * sizeof(char));
    current[0] = '\0';

    backtrack(digits , 0 , current , result , returnSize);

    free(current);
    return result;
}