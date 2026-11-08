#define Min(a, b) ((a) < (b) ? (a) : (b))

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** buckets;
    int size;
} HashMap;

HashMap* createHashMap(int size){
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (HashNode**)calloc(size , sizeof(HashNode*));
    return map;
}

void put(HashMap* map , int key , int value){
    int hash = abs(key) % map->size;
    HashNode* curr = map->buckets[hash];
    while(curr){
        if(curr->key == key){
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[hash];
    map->buckets[hash] = newNode;
}

int get(HashMap* map , int key){
    int hash = abs(key) % map->size;
    HashNode* curr = map->buckets[hash];
    while(curr){
        if(curr->key == key){
            return curr->value;
        }
        curr = curr->next;
    }
    return -2;
}

void freeHashMap(HashMap* map){
    for(int i = 0; i < map->size; i++){
        HashNode* curr = map->buckets[i];
        while(curr){
            HashNode* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

int minSubarray(int* nums, int numsSize, int p) {
    long long total = 0;
    for(int i = 0; i < numsSize; i++){
        total += nums[i];
    } 

    int target = total % p;
    if(target == 0) return 0;
    int bucketSize = Min(numsSize , 40001);
    HashMap* map = createHashMap(bucketSize);
    put(map , 0 , -1);

    long long prefix = 0;
    int res = numsSize;

    for(int i = 0; i < numsSize; i++){
        prefix = (prefix + nums[i]) % p;
        int need = (prefix - target + p) % p;
        int prevIdx = get(map , need);

        if(prevIdx != -2){
            res = Min(res , i - prevIdx);
        }
        put(map , (int)prefix , i);
    }

    freeHashMap(map);
    return res == numsSize ? -1: res;
}