#define Max(a , b) ((a) > (b) ? (a) : (b))
int rob(int* nums, int numsSize) {
    int rob1 = 0;
    int rob2 = 0;

    for(int i = 0; i < numsSize ;i++){
        int temp = Max(nums[i] + rob1 , rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}