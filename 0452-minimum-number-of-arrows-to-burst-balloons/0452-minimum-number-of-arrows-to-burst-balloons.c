#define min(a , b) ((a) < (b) ? (a) : (b))
int compare(const void* a , const void* b){
    int* A = *(int**)a;
    int* B = *(int**)b;

    if(A[0] < B[0]) return -1;
    if(A[0] > B[0]) return 1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize == 0){
        return 0;
    }

    qsort(points , pointsSize , sizeof(int*) , compare);
    int arrows = 1;
    int end = points[0][1];

    for(int i = 0; i < pointsSize; i++){
        if(points[i][0] > end){
            arrows++;
            end = points[i][1];
        }else{
            end = min(end , points[i][1]);
        }
    }
    return arrows;
}