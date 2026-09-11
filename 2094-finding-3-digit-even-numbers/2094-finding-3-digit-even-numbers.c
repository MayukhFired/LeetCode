/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Brute Force Approach

// int compare(const void* a , const void* b){
//     return (*(int*)a - *(int*)b);
// }

// int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
//     int* result = (int*)malloc(1000 * sizeof(int));
//     bool vis[1000] = {false};
//     int idx = 0;

//     for(int i = 0; i < digitsSize; i++){
//         if(digits[i] == 0){
//             continue;
//         }
//         for(int j = 0; j < digitsSize; j++){
//             for(int k = 0; k < digitsSize; k++){
//                 if(i == j || j == k || k == i){
//                     continue;
//                 }
//                 if(digits[k] % 2 != 0){
//                     continue;
//                 }
//                 int x = digits[i] * 100 + digits[j] * 10 + digits[k];
//                 if(!vis[x]){
//                     vis[x] = true;
//                     result[idx] = x;
//                     idx++;
//                 }
//             }
//         }
//     }

//     qsort(result , idx , sizeof(int), compare);
//     *returnSize = idx;
//     return result;
// }

//Optimal Approach
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize){
    bool vis[1000] = {false};
    int* result = (int*)malloc(450 * sizeof(int));
    int idx = 0;
    int count[10] = {0};
    for(int i = 0; i < digitsSize; i++){
        count[digits[i]]++;
    }

    for(int num = 100; num <= 998; num += 2){
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        count[d1]--;
        count[d2]--;
        count[d3]--;

        if(count[d1] >= 0 && count[d2] >= 0 && count[d3] >= 0){
            result[idx] = num;
            idx++;
        }

        count[d1]++;
        count[d2]++;
        count[d3]++;
    }

    *returnSize = idx;
    return result;
}