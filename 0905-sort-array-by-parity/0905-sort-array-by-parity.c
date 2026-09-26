/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* left , int* right){
    int temp = *left;
    *left = *right;
    *right = temp;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize* sizeof(int));
    if(result == NULL){
        return NULL;
    }
    memcpy(result , nums , numsSize * sizeof(int));
    int l = 0;
    int r = numsSize - 1;

    while(l < r){
        if(nums[l] % 2 > nums[r] % 2){
            swap(&nums[l] , &nums[r]);
        }

        if(nums[l] % 2 == 0){
            l++;
        }
        if(nums[r] % 2 != 0){
            r--;
        }
    }
    return nums;
}