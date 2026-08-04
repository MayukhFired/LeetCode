#define max(a , b) ((a) > (b) ? (a) : (b))
int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int max_length = 0;
    int zero_count = 0;
    for(int right = 0; right < numsSize ; right++){
        if(nums[right] == 0){
            zero_count++;
        }
        while(zero_count > k){
            if(nums[left] == 0){
                zero_count--;
            }
            left++;
        }
        max_length = max(max_length , right - left + 1);
    }
    return max_length;
}