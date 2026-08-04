#define max(a , b) ((a) > (b) ? (a) : (b))
int longestSubarray(int* nums, int numsSize) {
    int count = 0;
    int max_length = 0;
    int left = 0;
    for(int right = 0; right < numsSize ; right++){
        if(nums[right] == 0){
            count++;
        }
        while(count > 1){
            if(nums[left] == 0){
                count--;
            }
            left++;
        }
        max_length = max(max_length , right - left);
    }
    return max_length;
}