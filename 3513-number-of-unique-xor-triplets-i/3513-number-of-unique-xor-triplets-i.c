int uniqueXorTriplets(int* nums, int numsSize) {
    if(numsSize == 1 || numsSize == 2){
        return numsSize;
    }

    int ans = 1;
    while(ans <= numsSize){
        ans *= 2;
    }

    return ans;
}