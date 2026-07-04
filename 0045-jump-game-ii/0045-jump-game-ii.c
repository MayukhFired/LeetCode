int jump(int* nums, int numsSize) {
    if (numsSize <= 1){
        return 0;
    }

    int jumps = 0;
    int current_end = 0;
    int furthest = 0;

    for(int i = 0; i < numsSize - 1; i++){
        if(i + nums[i] > furthest){
            furthest = nums[i] + i;
        }

        if(i == current_end){
            jumps++;
            current_end = furthest;

            if(current_end >= numsSize -1){
                break;
            }
        }
    }
    return jumps;
}