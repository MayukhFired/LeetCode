#define Max(a , b) ((a) > (b) ? (a) : (b))
int longestCommonSubsequence(char* text1, char* text2) {
    int* dp = (int*)malloc(strlen(text1) * sizeof(int));
    int longest = 0;

    for(int i = 0; i < strlen(text2); i++){
        int curr_len = 0;
        for(int j = 0; j < strlen(text1); j++){
            if(dp[j] > curr_len){
                curr_len = dp[j];
            }else if(text2[i] == text1[j]){
                dp[j] = curr_len + 1;
                longest = Max(longest , curr_len + 1);
            }
        }
    }
    return longest;
}