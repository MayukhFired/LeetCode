long long gcd(long long a , long long b){
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int maxLength(int* nums, int numsSize) {
    int res = 0;
    for(int i = 0; i < numsSize ; i++){
        int prodVal = nums[i];
        int gcdVal = nums[i];
        int lcmVal = nums[i];
        for(int j = i + 1; j < numsSize; j++){
            prodVal = prodVal * nums[j];
            gcdVal = gcd(gcdVal , nums[j]);
            lcmVal = lcmVal * nums[j] / gcd(lcmVal , nums[j]);
            if(prodVal > gcdVal * lcmVal){
                break;
            }
            if(prodVal == gcdVal * lcmVal){
                int length = j - i + 1;
                res = fmax(res , length);
            }
        }
    }
    return res;
}