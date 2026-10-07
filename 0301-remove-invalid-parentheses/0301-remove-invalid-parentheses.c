/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** results;
int result_count;
int result_capacity;

int compareStrings(const void* a , const void* b){
    return strcmp(*(const char**)a , *(const char**)b);
}

void dfs(const char* s , int index , int rem_left , int rem_right , int balance , char* curr_str , int curr_len){
    if(s[index] == '\0'){
        if(rem_left == 0 && rem_right == 0 && balance == 0){
            curr_str[curr_len] = '\0';

            if(result_count >= result_capacity){
                result_capacity *= 2;
                results = realloc(results , result_capacity * sizeof(char*));
            }
            results[result_count++] = strdup(curr_str);
        }
        return;
    }

    if(balance < 0){
        return;
    }
    char c = s[index];

    if(c == '(' && rem_left > 0){
        dfs(s , index + 1 , rem_left - 1 , rem_right , balance , curr_str , curr_len);
    }else if(c == ')' && rem_right > 0){
        dfs(s , index + 1 , rem_left , rem_right - 1 , balance , curr_str , curr_len);
    }
    
    curr_str[curr_len] = c;

    if(c == '('){
        dfs(s , index + 1 , rem_left , rem_right , balance + 1 , curr_str , curr_len + 1);
    }else if(c == ')'){
        dfs(s , index + 1 , rem_left , rem_right , balance - 1 , curr_str , curr_len + 1);
    }else{
        dfs(s , index + 1 , rem_left , rem_right , balance , curr_str , curr_len + 1);
    }

}

char** removeInvalidParentheses(char* s, int* returnSize) {
    int rem_left = 0;
    int rem_right = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            rem_left++;
        }else if(s[i] == ')'){
            if(rem_left > 0){
                rem_left--;
            }else{
                rem_right++;
            }
        }
    }

    result_count = 0;
    result_capacity = 16;
    results = malloc(result_capacity * sizeof(char*));

    char* curr_str = malloc((len + 1) * sizeof(char));

    dfs(s , 0 , rem_left , rem_right , 0 , curr_str , 0);
    free(curr_str);

    if(result_count > 0){
        qsort(results , result_count , sizeof(char*) , compareStrings);
        int unique_idx = 0;for(int i = 1; i < result_count; i++){
            if(strcmp(results[i] , results[unique_idx]) != 0){
                results[++unique_idx] = results[i];
            }else{
                free(results[i]);
            }
        }
        *returnSize = unique_idx + 1;
    }else{
        results[0] = strdup("");
        *returnSize = 1;
    }
    return results;
}