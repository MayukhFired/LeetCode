// // int compare(const void *a , const void* b){
// //     int val_a = *(const int *)a;
// //     int val_b = *(const int *)b;
// //     return (val_a > val_b) - (val_a < val_b);
// // }

// int maxSubArray(int* nums, int numsSize) {
//     int max_sum = nums[0];
//     int current_sum = nums[0];

//     for(int i = 1; i < numsSize; i++){
//         if(current_sum < 0){
//             current_sum = nums[i];
//         }else{
//             current_sum += nums[i];
//         }
//             if(max_sum < current_sum){
//             max_sum = current_sum;
//         }
//     }

    

//     return max_sum;
// }

int maxSubArray(int* nums, int numsSize) {
    int res = nums[0];
    int maxEnding = nums[0];
    for (int i = 1; i < numsSize; i++) {
        maxEnding = (maxEnding + nums[i] > nums[i]) ? maxEnding + nums[i] : nums[i];
        res = (res > maxEnding) ? res : maxEnding;
    }
    return res;
}