#define max(a , b) ((a) > (b) ? (a) : (b))
#define min(a , b) ((a) < (b) ? (a) : (b))

int firstStableIndex(int* nums, int numsSize, int k) {
    if(numsSize <= 1){
        return 0;
    }

    
    for(int i = 0; i < numsSize; i++){
        int leftmax = nums[i];
        int rightmin = nums[i];
        
        for(int k = 0; k < i; k++){
            leftmax = max(leftmax , nums[k]);
        }

        for(int j = i + 1; j < numsSize; j++){
            rightmin = min(rightmin , nums[j]);
        }

        if(leftmax - rightmin <= k){
            return i;
        }
    }
    return -1;
}