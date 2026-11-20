typedef struct{
    int key;
    int length;
    UT_hash_handle hh;
} HashEntry;

int compare(const void* a , const void* b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int maxSelectedElements(int* nums, int numsSize) {
    qsort(nums , numsSize , sizeof(int) , compare);
    HashEntry* dp = NULL;
    HashEntry* entry;
    HashEntry* temp;
    int ans = 0;

    for(int i = 0; i < numsSize ; i++){
        for(int d = 1; d >= 0; d--){
            int key = nums[i] + d;
            int prevKey = key - 1;
            HASH_FIND_INT(dp , &prevKey , entry);
            int length = (entry == NULL ? 0 : entry->length) + 1;
            HASH_FIND_INT(dp , &key , entry);

            if(entry == NULL){
                entry = malloc(sizeof(HashEntry));
                entry->key = key;
                entry->length = 0;
                HASH_ADD_INT(dp , key , entry);
            }
            if(length > entry->length){
                entry->length = length;
            }
            if(entry->length > ans){
                ans = entry->length;
            }
        }
    }

    HASH_ITER(hh , dp , entry , temp){
        HASH_DEL(dp , entry);
        free(entry);
    }

    return ans;
}