/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a , const void* b){
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int* result = (int*)malloc(spellsSize * sizeof(int));
    qsort(potions , potionsSize , sizeof(int) , compare);
    for(int i = 0; i < spellsSize; i++){
        long long multi = (success + spells[i] - 1) / spells[i];
        int left = 0;
        int right = potionsSize;
        while(left < right){
            int mid = (left + right) / 2;
            if(potions[mid] >= multi){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        result[i] = potionsSize - left;
    }
    return result;
}