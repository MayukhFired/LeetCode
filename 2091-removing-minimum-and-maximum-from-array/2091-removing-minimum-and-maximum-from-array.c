int minimumDeletions(int* nums, int numsSize) {
    int minidx = 0;
    int maxidx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < nums[minidx]){
            minidx = i;
        }
        if(nums[i] > nums[maxidx]){
            maxidx = i;
        }
    }
    int l = fmin(minidx , maxidx);
    int r = fmax(minidx , maxidx);
    return fmin(fmin(r + 1 , numsSize - l) , l + 1 + numsSize - r);
}