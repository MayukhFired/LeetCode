int sumCounts(int* nums, int numsSize) {
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        int s_map[105] = {0};
        int s_len = 0;
        for(int j = i; j < numsSize; j++){
            if(s_map[nums[j]] == 0){
                s_map[nums[j]] = 1;
                s_len++;
            }
            res += s_len * s_len;
        }
    }
    return res;
}