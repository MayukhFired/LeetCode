/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int max_num = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
    }
    
    int* counts = (int*)calloc(max_num + 1, sizeof(int));
    long long* cnt_gcd = (long long*)calloc(max_num + 1, sizeof(long long));
    
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }
    
    for (int i = max_num; i >= 1; i--) {
        long long multiples_count = 0;
        for (int j = i; j <= max_num; j += i) {
            multiples_count += counts[j];
        }
        
        long long total_pairs = (multiples_count * (multiples_count - 1)) / 2;
        
        for (int j = 2 * i; j <= max_num; j += i) {
            total_pairs -= cnt_gcd[j];
        }
        cnt_gcd[i] = total_pairs;
    }
    
    long long* prefix_sums = (long long*)calloc(max_num + 1, sizeof(long long));
    for (int i = 1; i <= max_num; i++) {
        prefix_sums[i] = prefix_sums[i - 1] + cnt_gcd[i];
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        long long target = queries[i];
        
        int left = 1;
        int right = max_num;
        int ans = max_num;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefix_sums[mid] > target) {
                ans = mid;   
                right = mid - 1;
            } else {
                left = mid + 1;   
            }
        }
        result[i] = ans;
    }
    free(counts);
    free(cnt_gcd);
    free(prefix_sums);
    
    return result;
}