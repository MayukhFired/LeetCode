#define Max(a , b) ((a) > (b) ? (a) : (b))
int longestMonotonicSubarray(int* nums, int numsSize) {
    int max_length = 1;
    for(int start = 0; start < numsSize; start++){
        int curr_length = 1;
        for(int pos = start + 1; pos < numsSize; pos++){
            if(nums[pos] > nums[pos - 1]){
                curr_length++;
            }else{
                break;
            }
        }
        max_length = Max(max_length , curr_length);
    }

    for(int start = 0; start < numsSize; start++){
        int curr_length = 1;
        for(int pos = start + 1; pos < numsSize; pos++){
            if(nums[pos] < nums[pos - 1]){
                curr_length++;
            }else{
                break;
            }
        }
        max_length = Max(max_length , curr_length);
    }

    return max_length;
}