/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(numsSize* sizeof(char*));
    int count = 0;
    int i = 0;
    while(i < numsSize){
        int start = nums[i];
            while(i + 1 < numsSize && (long)nums[i] + 1 == nums[i + 1]){
            i++;
        }

        result[count] = (char*)malloc(25 * sizeof(char));
        if(start == nums[i]){
            sprintf(result[count] , "%d" , start);
        }else{
            sprintf(result[count] , "%d->%d" , start , nums[i]);
        }

        count++;
        i++;
    }
    *returnSize = count;
    return result;
}