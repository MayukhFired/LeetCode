int nCr(int n, int r, int k_cap) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) {
        r = n - r;
    }

    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i; // Safe to multiply using long long
        
        // Direct, accurate capping without truncation errors
        if (res >= k_cap) {
            return k_cap;
        }
    }
    return (int)res;
}


int arrangements(int* counts, int k_cap) {
    int total = 0;
    for (int i = 0; i < 26; i++) {
        total += counts[i];
    }

    long long ways = 1;
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            int combinations = nCr(total, counts[i], k_cap);
            if (combinations == 0) return 0;
            
            ways *= combinations;
            // Direct cap validation
            if (ways >= k_cap) {
                return k_cap;
            }
            total -= counts[i];
        }
    }
    return (int)ways;
}


char* smallestPalindrome(char* s, int k) {
    int len = strlen(s);
    int counts[26] = {0};
    char mid_char = '\0';

    for(int i = 0;i < len; i++){
        counts[s[i] - 'a']++;
    }

    int half_counts[26] = {0};
    int total_len = 0;
    for(int i = 0; i < 26; i++){
        half_counts[i] = counts[i] / 2;
        total_len += half_counts[i];

        if(counts[i] % 2 != 0){
            mid_char = 'a' + i;
        }
    }

    if(arrangements(half_counts , k) < k){
        char* empty_res = (char*)malloc(sizeof(char));
        empty_res[0] = '\0';
        return empty_res;
    }

    char* left_half = (char*)malloc((total_len + 1)* sizeof(char));
    int idx = 0;
    for(int step = 0; step < total_len; step++){
        for(int i = 0; i < 26; i++){
            if(half_counts[i] == 0) continue;
            half_counts[i]--;
            int w = arrangements(half_counts , k);
            if(w >= k){
                left_half[idx++] = 'a' + i;
                break;
            }else{
                k -= w;
                half_counts[i]++;
            }
        }
    }
    left_half[idx] = '\0';

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int r_idx = 0;
    for(int i = 0; i < total_len; i++){
        result[r_idx++] = left_half[i];
    }

    if(mid_char != '\0'){
        result[r_idx++] = mid_char;
    }

    for(int i = total_len - 1; i >= 0; i--){
        result[r_idx++] = left_half[i];
    }

    result[r_idx] = '\0';
    free(left_half);
    return result;
}