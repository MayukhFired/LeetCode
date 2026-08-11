int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}
int missingInteger(int* nums, int numsSize) {
    int seq_sum = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1] + 1){
            seq_sum += nums[i];
        }else{
            break;
        }
    }

    qsort(nums , numsSize , sizeof(int) , compare);
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == seq_sum){
            seq_sum++;
        }
    }
    return seq_sum;
}