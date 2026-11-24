long long gcd(long long a , long long b){
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int maxLength(int* nums, int numsSize) {
// 1----------------------------------------------------------------------------1
//     int res = 0;
//     for(int i = 0; i < numsSize ; i++){
//         int prodVal = nums[i];
//         int gcdVal = nums[i];
//         int lcmVal = nums[i];
//         for(int j = i + 1; j < numsSize; j++){
//             prodVal = prodVal * nums[j];
//             gcdVal = gcd(gcdVal , nums[j]);
//             lcmVal = lcmVal * nums[j] / gcd(lcmVal , nums[j]);
//             if(prodVal > gcdVal * lcmVal){
//                 break;
//             }
//             if(prodVal == gcdVal * lcmVal){
//                 int length = j - i + 1;
//                 res = fmax(res , length);
//             }
//         }
//     }
//     return res;
// 1-----------------------------------------------------------------------------------1

    int res = 2;
    int prod_val = 1;
    int n = numsSize;
    int start = 0;
    int end = 0;

    while(end < n){
        while(gcd(prod_val , nums[end]) > 1){
            prod_val /= nums[start];
            start++;
        }
        prod_val *= nums[end];
        res = fmax(res , end - start + 1);
        end++;
    }
    return res;
}