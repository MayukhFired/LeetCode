char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int min_len = n + 1;
    int best_left = -1;
    int ones = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        if(s[r] == '1'){
            ones++;
        }
        while(ones == k){
            int curr_len = r - l + 1;
            if(curr_len < min_len){
                min_len = curr_len;
                best_left = l;
            }else if(curr_len == min_len){
                if(best_left == -1 || strncmp(&s[l] , &s[best_left] , curr_len) < 0){
                    best_left = l;
                }
            }
            if(s[l] == '1'){
                ones--;
            }
            l++;
        }
    }
    char* result;
    if (best_left == -1) {
        result = (char*)malloc(1 * sizeof(char));
        result[0] = '\0';
    } else {
        result = (char*)malloc((min_len + 1) * sizeof(char));
        strncpy(result, &s[best_left], min_len);
        result[min_len] = '\0';
    }
    return result;
}