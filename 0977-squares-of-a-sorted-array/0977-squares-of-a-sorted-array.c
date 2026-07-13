/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    // if(numsSize == 1){
    //     nums[0] = nums[0] * nums[0];
    //     return nums;
    // }

    int left = 0; 
    int right = numsSize - 1;
    int index = numsSize - 1;
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));

    while(left <= right){
        // int square_left = nums[left] * nums[left];
        // int square_right = nums[right] * nums[right];

        if(nums[left] * nums[left] > nums[right] * nums[right]){
            result[index] = nums[left] * nums[left];
            left++;
        }else{
            result[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }

    return result;
}