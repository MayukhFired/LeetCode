int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int result = nums[0] + nums[1] + nums[2];

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize; i++){
        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == target){
                return sum;
            }

            if(abs(target - sum) < abs(target - result)){
                result = sum;
            }

            if(sum < target){
                left++;
            }else if(sum > target){
                right--;
            }else{
                return target;
            }
        }
    }

    return result;
}