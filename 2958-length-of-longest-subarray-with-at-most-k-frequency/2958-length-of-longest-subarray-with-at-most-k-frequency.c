#define Max(a , b) ((a) > (b) ? (a) : (b))
int compare(const void* a , const void* b){
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb);
}
int maxSubarrayLength(int* nums, int numsSize, int k) {
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        sorted[i] = nums[i];
    }
    qsort(sorted , numsSize , sizeof(int), compare);
    int* com = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        int low = 0;
        int high = numsSize - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(sorted[mid] == nums[i]){
                com[i] = mid;
                break;
            }else if(sorted[mid] < nums[i]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    int* freq = (int*)calloc(numsSize , sizeof(int));
    int left = 0;
    int max_len = 0;
    for(int right = 0; right < numsSize ; right++){
        freq[com[right]]++;
        while(freq[com[right]] > k){
            freq[com[left]]--;
            left++;
        }
        max_len = Max(max_len , right - left + 1);
    }
    free(sorted);
    free(com);
    free(freq);
    return max_len;
}