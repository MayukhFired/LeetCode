int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int reductionOperations(int* nums, int numsSize) {
    qsort(nums , numsSize , sizeof(int) , compare);
    int ans = 0;
    int steps = 0;

    for(int i = 1;i< numsSize; i++){
        if(nums[i] != nums[i - 1]){
            steps++;
        }
        ans += steps;
    }
    return ans;
}