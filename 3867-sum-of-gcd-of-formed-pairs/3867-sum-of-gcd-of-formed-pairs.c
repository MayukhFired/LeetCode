// int sort(int* prefixGcd , int length){
//     for(int i = 0; i < length; i++){
//         for(int j = 0; j < length - i - 1; j++){
//             if(prefixGcd[j+1] < prefixGcd[j]){
//                 int temp = prefixGcd[j];
//                 prefixGcd[j + 1] = prefixGcd[j];
//                 prefixGcd[j + 1] = temp;
//             }
//         }
//     }

//     return prefixGcd;
// }

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int gcd(int a , int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

long long gcdSum(int* nums, int numsSize) {
    int* prefixGcd = (int*)malloc(numsSize * sizeof(int));
    int max = nums[0];
    int index = 0;
    for(int i = 0; i < numsSize; i++){
        if(max < nums[i]){
            max = nums[i];
            prefixGcd[index++] = gcd(nums[i] , max);
        }else{
            prefixGcd[index++] = gcd(nums[i] , max);
        }
    }

    // sort(prefixGcd , numsSize);
    qsort(prefixGcd, numsSize, sizeof(int), compare);
    int left = 0;
    int right = numsSize - 1;
    long long sum = 0;
    while(left < right){
        sum += gcd(prefixGcd[left] , prefixGcd[right]);
        left++;
        right--;
    }

    free(prefixGcd);
    return sum;
}