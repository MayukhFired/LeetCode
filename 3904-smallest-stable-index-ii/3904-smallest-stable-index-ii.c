#define max(a , b) ((a) > (b) ? (a) : (b))
#define min(a , b) ((a) < (b) ? (a) : (b))

int firstStableIndex(int* nums, int numsSize, int k) {
    int* minIndex = (int*)malloc(numsSize * sizeof(int));
    int minElement = INT_MAX;

    for(int i = numsSize - 1; i >= 0; i--){
        minElement = min(minElement , nums[i]);
        minIndex[i] = minElement;
    }

    int maxElement = INT_MIN;
    for(int i = 0; i < numsSize ; i++){
        maxElement = max(maxElement , nums[i]);

        if(maxElement - minIndex[i] <= k){
            return i;
        }
    }
    return -1;
}