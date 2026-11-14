// 1--------------------------------------------------1
// int compare(const void* a , const void* b){
//     return (*(int*)a - *(int*)b);
// }
// 1--------------------------------------------------1

int reductionOperations(int* nums, int numsSize) {
// 1-----------------------------------------------------------1
    // qsort(nums , numsSize , sizeof(int) , compare);
    // int ans = 0;
    // int steps = 0;

    // for(int i = 1;i< numsSize; i++){
    //     if(nums[i] != nums[i - 1]){
    //         steps++;
    //     }
    //     ans += steps;
    // }
    // return ans;
// 1---------------------------------------------------------1
    int ans = 0;
    int steps = 0;
    int max_val = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        max_val = fmax(max_val ,nums[i]);
    }

    int* freq = (int*)calloc((max_val + 1) , sizeof(int));
    for(int i = 0; i < numsSize; i++){
        freq[nums[i]]++;
    }

    for(int val = 1; val <= max_val; val++){
        if(freq[val] > 0){
            ans += freq[val] * steps;
            steps++;
        }
    }

    return ans;
}