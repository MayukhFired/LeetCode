#define Max(a , b) ((a) > (b) ? (a) : (b))

int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;

    int nonzeros1[900];
    int nonzeros2[900];
    int count1 = 0;
    int count2 = 0;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(img1[r][c] == 1){
                nonzeros1[count1++] = r * n + c;
            }
            if(img2[r][c] == 1){
                nonzeros2[count2++] = r * n + c;
            }
        }
    }

    int shiftCounts[60][60];
    memset(shiftCounts , 0 , sizeof(shiftCounts));
    int maxOverlap = 0;

    for(int i = 0; i < count1; i++){
        int r1 = nonzeros1[i] / n;
        int c1 = nonzeros1[i] % n;
        for(int j = 0; j < count2; j++){
            int r2 = nonzeros2[j] / n;
            int c2 = nonzeros2[j] % n;


            int rowShiftIdx = (r2 - r1) + n;
            int colShiftIdx = (c2 - c1) + n;

            shiftCounts[rowShiftIdx][colShiftIdx]++;
            maxOverlap = Max(maxOverlap , shiftCounts[rowShiftIdx][colShiftIdx]);
        }
    }
    return maxOverlap;
}