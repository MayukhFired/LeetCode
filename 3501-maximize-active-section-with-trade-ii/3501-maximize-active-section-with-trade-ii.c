/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #define Max(a , b) ((a > b) ? a : b)
 #define Min(a , b) ((a < b) ? a : b)

 typedef struct{
    int start;
    int end;
    int length;
 } Zeroblocks;

int get_truncated_gain(Zeroblocks* zero_blocks, int k, int l, int r) {
    int start1 = Max(zero_blocks[k].start, l);
    int end1 = Min(zero_blocks[k].end, r);
    int len1 = (start1 <= end1) ? (end1 - start1 + 1) : 0;

    int start2 = Max(zero_blocks[k+1].start, l);
    int end2 = Min(zero_blocks[k+1].end, r);
    int len2 = (start2 <= end2) ? (end2 - start2 + 1) : 0;

    return len1 + len2;
}
int* maxActiveSectionsAfterTrade(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    int total_ones = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') total_ones++;
    }

    Zeroblocks * zero_blocks = (Zeroblocks*)malloc((n + 1) * sizeof(Zeroblocks));
    int num_blocks = 0;
    int i = 0;
    while(i < n){
        if(s[i] == '0'){
            int start = i;
            while(i < n && s[i] == '0') i++;
            zero_blocks[num_blocks].start = start;
            zero_blocks[num_blocks].end = i - 1;
            zero_blocks[num_blocks].length = i - start;
            num_blocks++;
        }else{
            i++;
        }
    }

    int m = num_blocks -1;
    int** st = NULL;
    int max_log = 0;
    if(m > 0){
        while((1 << max_log) <= m) max_log++;
        st = (int**)malloc(sizeof(int*) * m);
        for(int k = 0; k < m; k++){
            st[k] = (int*)malloc(max_log * sizeof(int));
            st[k][0] = zero_blocks[k].length + zero_blocks[k + 1].length;
        }

        for(int j = 1 ; j < max_log; j++){
            for(int k = 0; k <= m - (1 << j); k++){
                st[k][j] = Max(st[k][j - 1] , st[k + (1 << (j - 1))][j - 1]);
            }
        }
    }

        for(int q = 0; q < queriesSize; q++){
        int l = queries[q][0];
        int r = queries[q][1];

        // Binary search for the first pair k where zero_blocks[k].end >= l
        int L_pair = m;
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (zero_blocks[mid].end >= l) { // FIX: strict internal boundary check
                L_pair = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Binary search for the last pair k where zero_blocks[k+1].start <= r
        int R_pair = -1;
        low = 0; high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (zero_blocks[mid + 1].start <= r) { // FIX: strict internal boundary check
                R_pair = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int max_gain = 0;
        if (L_pair <= R_pair && m > 0) {
            // Check the boundary pairs with precise truncation boundaries
            max_gain = Max(get_truncated_gain(zero_blocks, L_pair, l, r), 
                           get_truncated_gain(zero_blocks, R_pair, l, r));
            
            // Check the fully interior pairs using the Sparse Table
            if (L_pair + 1 <= R_pair - 1) {
                int length = (R_pair - 1) - (L_pair + 1) + 1;
                int j = 0;
                while((1 << (j + 1)) <= length) j++;
                int st_gain = Max(st[L_pair + 1][j] , st[(R_pair - 1) - (1 << j) + 1][j]);
                max_gain = Max(max_gain, st_gain);
            }
        }
        ans[q] = total_ones + max_gain;
    }


    if(m > 0){
        for(int k = 0; k < m; k++){
            free(st[k]);
        }
        free(st);
    }

    free(zero_blocks);
    return ans;
}

