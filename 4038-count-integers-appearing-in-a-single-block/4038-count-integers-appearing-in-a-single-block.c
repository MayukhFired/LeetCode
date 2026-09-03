int countSpecialIntegers(int* nums, int numsSize) {
    if(numsSize <= 0){
        return 0;
    }
    int maxVal = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > maxVal){
            maxVal = nums[i];
        }
    }

    int* total_count = (int*)calloc((maxVal + 1) , sizeof(int));
    int* block_len = (int*)calloc((maxVal + 1) , sizeof(int));
    int* d_nums = (int*)calloc((maxVal + 1) , sizeof(int));

    for(int i = 0; i < numsSize; i++){
        total_count[nums[i]]++;
        d_nums[nums[i]] = 1;
    }

    int i = 0;
    while(i < numsSize){
        int curr_num = nums[i];
        int curr_len = 0;
        while(i < numsSize && nums[i] == curr_num){
            curr_len++;
            i++;
        }
        block_len[curr_num] = curr_len;
    }

    int special_count = 0;
    for(int val = 0; val <= maxVal; val++){
        if(d_nums[val] && total_count[val] == block_len[val]){
            special_count++;
        }
    }

    free(total_count);
    free(d_nums);
    free(block_len);

    return special_count;
}