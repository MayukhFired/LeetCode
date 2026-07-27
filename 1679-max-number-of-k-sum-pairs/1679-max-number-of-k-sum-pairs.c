int compare(const void* a , const void* b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 < num2) return -1;
    if(num1 > num2) return 1;
    return 0;
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums , numsSize , sizeof(int) , compare);
    int left = 0;
    int right = numsSize - 1;
    int count = 0;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == k){
            count++;
            left++;
            right--;
        }else if(sum > k){
            right--;
        }else{
            left++;
        }
    }

    return count;
}