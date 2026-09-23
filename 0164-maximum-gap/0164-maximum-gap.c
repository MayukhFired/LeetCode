#define Max(a , b) ((a) > (b) ? (a) : (b))
#define Min(a , b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if(numsSize < 2){
        return 0;
    }

    int min_val = nums[0];
    int max_val = nums[0];
    for(int i = 0; i < numsSize; i++){
        max_val = Max(max_val , nums[i]);
        min_val = Min(min_val , nums[i]);
    }

    if(max_val == min_val){
        return 0;
    }

    int bucket_size = Max(1 , (max_val - min_val) / (numsSize - 1));
    int bucket_count = (max_val - min_val) / bucket_size + 1;

    int* bucket_min = (int*)malloc(bucket_count * sizeof(int));
    int* bucket_max = (int*)malloc(bucket_count * sizeof(int));

    for(int i = 0; i < bucket_count; i++){
        bucket_min[i] = INT_MAX;
        bucket_max[i] = INT_MIN;
    }

    for(int i = 0; i < numsSize; i++){
        int bucket_idx = (nums[i] - min_val) / bucket_size;
        bucket_min[bucket_idx] = Min(bucket_min[bucket_idx] , nums[i]);
        bucket_max[bucket_idx] = Max(bucket_max[bucket_idx] , nums[i]);
    }

    int max_gap = 0;
    int previous_max = min_val;
    for(int i = 0; i < bucket_count; i++){
        if(bucket_min[i] == INT_MAX){
            continue;
        }

        max_gap = Max(max_gap , bucket_min[i] - previous_max);
        previous_max = bucket_max[i];
    }

    free(bucket_max);
    free(bucket_min);

    return max_gap;
}