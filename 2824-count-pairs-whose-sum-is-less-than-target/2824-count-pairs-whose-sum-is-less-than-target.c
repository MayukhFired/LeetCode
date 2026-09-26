int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int countPairs(int* nums, int numsSize, int target) {
    qsort(nums , numsSize , sizeof(int) , compare);
    int left = 0;
    int right = numsSize - 1;
    int count = 0;

    while(left < right){
        if(nums[left] + nums[right] < target){
            count += (right - left);
            left++;
        }else{
            right--;
        }
    }
    return count;
}