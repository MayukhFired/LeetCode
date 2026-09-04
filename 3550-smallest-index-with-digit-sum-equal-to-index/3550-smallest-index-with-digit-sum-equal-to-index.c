int smallestIndex(int* nums, int numsSize) {
    int sum = 0;
    int result = -1;
    for(int i = 0; i < numsSize; i++){
        int curr_num = nums[i];
        while(curr_num != 0){
            int temp = curr_num % 10;
            sum += temp;
            curr_num /= 10;
        }

        if(sum == i){
            result = i;
            break;
        }else{
            sum = 0;
        }
    }
    return result;
}