// 1---------------------------------------------------------------------1
// typedef struct{
//     int key;
//     int length;
//     UT_hash_handle hh;
// } HashEntry;
// 1----------------------------------------------------------------1

int compare(const void* a , const void* b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int maxSelectedElements(int* nums, int numsSize) {
// 1--------------------------------------------------------------------------------------------1
    // qsort(nums , numsSize , sizeof(int) , compare);
    // HashEntry* dp = NULL;
    // HashEntry* entry;
    // HashEntry* temp;
    // int ans = 0;

    // for(int i = 0; i < numsSize ; i++){
    //     for(int d = 1; d >= 0; d--){
    //         int key = nums[i] + d;
    //         int prevKey = key - 1;
    //         HASH_FIND_INT(dp , &prevKey , entry);
    //         int length = (entry == NULL ? 0 : entry->length) + 1;
    //         HASH_FIND_INT(dp , &key , entry);

    //         if(entry == NULL){
    //             entry = malloc(sizeof(HashEntry));
    //             entry->key = key;
    //             entry->length = 0;
    //             HASH_ADD_INT(dp , key , entry);
    //         }
    //         if(length > entry->length){
    //             entry->length = length;
    //         }
    //         if(entry->length > ans){
    //             ans = entry->length;
    //         }
    //     }
    // }

    // HASH_ITER(hh , dp , entry , temp){
    //     HASH_DEL(dp , entry);
    //     free(entry);
    // }

    // return ans;
// 1-----------------------------------------------------------------------1
    qsort(nums , numsSize , sizeof(int) , compare);
    int best = 1;
    int keep = 1;
    int bump = 1;
    int last = -10;

    for(int i = 0; i < numsSize; i++){
        switch (nums[i] - last) {
            case 0: bump = keep + 1; break;
            case 1: ++keep , ++bump; break;
            case 2: keep = bump + 1 , bump = 1; break;
            default: keep = 1 , bump = 1;
        }
        best = fmax(best , fmax(keep , bump));
        last = nums[i];
    }
    return best;
}