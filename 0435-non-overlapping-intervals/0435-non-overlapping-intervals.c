int compare(const void* a , const void* b){
    int* A = *(int**)a;
    int* B = *(int**)b;

    if(A[1] < B[1]) return -1;
    if(A[1] > B[1]) return 1;
    return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if(intervalsSize == 0){
        return 0;
    }

    qsort(intervals , intervalsSize , sizeof(int*) , compare);
    int res = 0;
    int prev = intervals[0][1];

    for(int i = 1 ; i < intervalsSize; i++){
        if(prev > intervals[i][0]){
            res++;
        }else{
            prev = intervals[i][1];
        }
    }
    return res;
}