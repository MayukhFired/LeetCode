int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b); 
}
long long maxAlternatingSum(int* nums, int numsSize) {
    int* multi = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0;i < numsSize; i++){
        multi[i] = 1LL * nums[i] * nums[i];
    }

    qsort(multi , numsSize , sizeof(int) , compare);

    long long ans = 0;
    for(int i = 0; i < numsSize; i++){
        if(i < numsSize / 2){
            ans -= multi[i];
        }else{
            ans += multi[i];
        }
    }
    return ans;
}