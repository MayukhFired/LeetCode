#define max(a , b) ((a) > (b) ? (a) : (b))

int minOperations(int* nums, int numsSize, int x) {
    int left = 0;
    int max_len = -1;
    int curr_sum = 0;
    int k = 0;
    for(int i = 0; i < numsSize; i++){
        k += nums[i];
    }

    k -= x;
    if(k == 0){
        return numsSize;
    }
    if(k < 0){
        return -1;
    }
    for(int right = 0; right < numsSize; right++){
        curr_sum += nums[right];
        while(curr_sum > k){
            curr_sum -= nums[left++];
        }
        if(curr_sum == k){
            max_len = max(max_len , right - left + 1);
        }
    }

    return max_len == -1 ? -1 : numsSize - max_len; 
}