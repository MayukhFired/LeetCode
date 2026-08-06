int compare(const void* a , const void* b){
    return(*(int*)b - *(int*)a);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    qsort(arr , arrSize , sizeof(int) , compare);
    int* counts = (int*)malloc(arrSize *sizeof(int));
    int countSize = 0;
    int currentCount = 1;
    for(int i = 0;i < arrSize; i++){
        if(i == arrSize - 1 || arr[i] != arr[i + 1]){
            counts[countSize++] = currentCount;
            currentCount = 1;
        }else{
            currentCount++;
        }
    }
    qsort(counts , countSize , sizeof(int) , compare);
    for(int i = 0; i < countSize - 1; i++){
        if(counts[i] == counts[i + 1]){
            free(counts);
            return false;
        }
    }
    return true;
}