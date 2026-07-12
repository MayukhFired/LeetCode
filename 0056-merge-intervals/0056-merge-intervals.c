/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int compare(const void *a , const void *b){
    int *startA = *(int**)a;
    int *startB = *(int**)b;
    return startA[0] - startB[0];
 }

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize <= 0){
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals , intervalsSize , sizeof(int*) , compare);

    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int count = 0;
    merged[0] = (int*)malloc(2 * sizeof(int));
    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    count = 1;

    for(int i = 1; i < intervalsSize; i++){

        if(intervals[i][0] <=  merged[count-1][1]){
            if(intervals[i][1] >  merged[count-1][1]){
                merged[count - 1][1] = intervals[i][1];
            }
        }else{
            merged[count] = (int*)malloc(2 * sizeof(int));
            merged[count][0] = intervals[i][0];
            merged[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return merged;
}