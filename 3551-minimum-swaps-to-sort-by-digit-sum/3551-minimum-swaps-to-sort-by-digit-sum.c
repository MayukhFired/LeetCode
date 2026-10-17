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

int minSwaps(int* nums, int numsSize) {
    Elem* elems = (Elem*)malloc(numsSize * sizeof(Elem));
    for(int i = 0; i < numsSize; i++){
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

    qsort(elems , numsSize , sizeof(Elem) , compare);

    int* targetPos = (int*)malloc(numsSize * sizeof(int));
    for(int pos = 0; pos < numsSize; pos++){
        targetPos[elems[pos].origIdx] = pos;
    }

    bool* visited =  (bool*)calloc(numsSize , sizeof(bool));
    int cycles = 0;
    for(int i = 0; i < numsSize; i++){
        if(!visited[i]){
            cycles++;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                j = targetPos[j];
            }
        }
    }

    free(elems);
    free(visited);
    free(targetPos);
    return numsSize - cycles;
}