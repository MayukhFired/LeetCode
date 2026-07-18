int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int findGCD(int* nums, int numsSize) {
    int largest = nums[0];
    int small = nums[0];

    for(int i = 1; i < numsSize; i++){
        if(largest < nums[i]){
            largest = nums[i];
        }

        if(nums[i] < small){
            small = nums[i];
        }
    }

    return gcd(largest , small);
}