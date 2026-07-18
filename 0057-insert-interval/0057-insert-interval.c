/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 #define min(a , b) ((a) < (b) ? (a) : (b))
 #define max(a , b) ((a) > (b) ? (a) : (b))
 
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int i = 0;
    int index = 0;

    while(i < intervalsSize && intervals[i][1] < newInterval[0]){
        result[index] = (int*)malloc(2* sizeof(int));
        result[index][0] = intervals[i][0];
        result[index][1] = intervals[i][1];
        (*returnColumnSizes)[index] = 2;
        index++;
        i++;
    }

    while(i < intervalsSize && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0] , intervals[i][0]);
        newInterval[1] = max(newInterval[1] , intervals[i][1]);
        i++;
    }
    
    result[index] = (int*)malloc(2 * sizeof(int));
    result[index][0] = newInterval[0];
    result[index][1] = newInterval[1];
    (*returnColumnSizes)[index] = 2;
    index++;

    while(i < intervalsSize){
        result[index] = (int*)malloc(2 * sizeof(int));
        result[index][0] = intervals[i][0];
        result[index][1] = intervals[i][1];
        (*returnColumnSizes)[index] = 2;
        index++;
        i++;
    }

    *returnSize = index;
    return result;
}