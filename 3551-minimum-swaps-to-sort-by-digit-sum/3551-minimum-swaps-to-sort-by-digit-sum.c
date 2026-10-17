// 1--------------------------This also includes in the first solution------------------------------------1
typedef struct{
    int digitSum;
    int value;
    int origIdx;
} Elem;

int compare(const void* a , const void* b){
    Elem* ea = (Elem*)a;
    Elem* eb = (Elem*)b;
    if(ea->digitSum != eb->digitSum){
        return ea->digitSum - eb->digitSum;
    }
    return ea->value - eb->value;
}
// -----------------------This also includes in the first solution--------------------------------------

int find(int* parent , int x){
    if(parent[x] != x){
        parent[x] = find(parent , parent[x]);
    }
    return parent[x];
}

int minSwaps(int* nums, int numsSize) {
// 1---------------------------------------------------------------------------------------------1
    // Elem* elems = (Elem*)malloc(numsSize * sizeof(Elem));
    // for(int i = 0; i < numsSize; i++){
    //     int x = nums[i];
    //     int sum = 0;
    //     while(x > 0){
    //         sum += x % 10;
    //         x /= 10;
    //     }
    //     elems[i].digitSum = sum;
    //     elems[i].value = nums[i];
    //     elems[i].origIdx = i;
    // }

    // qsort(elems , numsSize , sizeof(Elem) , compare);

    // int* targetPos = (int*)malloc(numsSize * sizeof(int));
    // for(int pos = 0; pos < numsSize; pos++){
    //     targetPos[elems[pos].origIdx] = pos;
    // }

    // bool* visited =  (bool*)calloc(numsSize , sizeof(bool));
    // int cycles = 0;
    // for(int i = 0; i < numsSize; i++){
    //     if(!visited[i]){
    //         cycles++;
    //         int j = i;
    //         while(!visited[j]){
    //             visited[j] = true;
    //             j = targetPos[j];
    //         }
    //     }
    // }

    // free(elems);
    // free(visited);
    // free(targetPos);
    // return numsSize - cycles;
// 1---------------------------------------------------------------------------------------------1
    Elem* elems = (Elem*)malloc(numsSize * sizeof(Elem));
    for(int i = 0; i <numsSize; i++){
        int x = nums[i];
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        elems[i].digitSum = sum;
        elems[i].value = nums[i];
        elems[i].origIdx = i;
    }
    qsort(elems , numsSize, sizeof(Elem) , compare);

    int* targetPos = (int*)malloc(numsSize * sizeof(int));
    for(int pos = 0; pos < numsSize; pos++){
        targetPos[elems[pos].origIdx] = pos;
    }

    int* parent = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        parent[i] = i;
    }
    int components = numsSize;

    for(int i = 0; i < numsSize; i++){
        int ri = find(parent , i);
        int rj = find(parent , targetPos[i]);
        if(ri != rj){
            parent[ri] = rj;
            components--;
        }
    }

    free(elems);
    free(parent);
    free(targetPos);
    return numsSize - components;
}