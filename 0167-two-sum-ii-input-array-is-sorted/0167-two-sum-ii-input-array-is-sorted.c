/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    int index = 0;

    int left = 0 ; 
    int right = numbersSize - 1;
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            result[index++] = left + 1;
            result[index++] = right + 1;
            break;
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }

    return result;
}