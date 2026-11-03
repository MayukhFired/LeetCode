#define Max(a , b) ((a) > (b) ? (a) : (b))
int minMoves(int* nums, int numsSize) {
    int max_nums = nums[0];
    for(int i = 1; i < numsSize; i++){
        max_nums = Max(max_nums , nums[i]);
    }

    int total = 0;
    for(int i = 0; i < numsSize; i++){
        total += max_nums - nums[i];
    }
    return total;
}