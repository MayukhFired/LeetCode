/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int freq[201];

int compare(const void* a , const void* b){
    int valA = *(const int*)a;
    int valB = *(const int*)b;

    int freqA = freq[valA + 100];
    int freqB = freq[valB + 100];

    if(freqA != freqB){
        return freqA - freqB;
    }
    return valB - valA;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    for(int i = 0; i <= 200; i++){
        freq[i] = 0;
    }

    for(int i = 0; i < numsSize; i++){
        freq[nums[i] + 100]++;
    }

    qsort(nums , numsSize , sizeof(int) , compare);
    *returnSize = numsSize;
    return nums;
}