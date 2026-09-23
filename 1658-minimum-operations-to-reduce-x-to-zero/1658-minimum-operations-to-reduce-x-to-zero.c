#define max(a , b) ((a) > (b) ? (a) : (b))

int minOperations(int* nums, int numsSize, int x) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }

    int target = sum - x;
    if(target < 0){
        return -1;
    }
    if(target == 0){
        return numsSize;
    }

    int max_len = -1;
    int current_sum = 0;
    int left = 0;

    for(int right = 0; right < numsSize; right++){
        current_sum += nums[right];
        while(current_sum > target && left <= right){
            current_sum -= nums[left];
            left++;
        }
        if(current_sum == target){
            max_len = max(max_len , right - left + 1);
        }
    }

    if(max_len != -1){
        return numsSize - max_len;
    }else{
        return -1;
    }
}