/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums , numsSize , sizeof(int) , compare);
    int* res = (int*)malloc(numsSize * sizeof(int));
    int idx = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target){
            res[idx++] = i;
        }else{
            continue;
        }
    }
    *returnSize = idx;
    return res;
}