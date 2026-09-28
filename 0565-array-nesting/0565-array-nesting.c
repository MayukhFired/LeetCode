#define Max(a , b) ((a) > (b) ? (a) : (b))

int arrayNesting(int* nums, int numsSize) {
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != -1){
            int start = i;
            int count = 0;

            while(nums[start] != -1){
                int next_idx = nums[start];
                nums[start] = -1;
                start = next_idx;
                count++;
            }
            res = Max(res , count);
        }
    }
    return res;
}