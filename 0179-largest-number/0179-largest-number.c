#define size 10000000007LL

int compare(const void* a , const void* b){
    char str1[40];
    char str2[40];

    sprintf(str1 , "%d%d" , *(const int*)a , *(const int*)b);
    sprintf(str2 , "%d%d" , *(const int*)b , *(const int*)a);

    return strcmp(str2 , str1);
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums , numsSize , sizeof(int) , compare);
    if(nums[0] == 0){
        char* res = (char*)malloc(2 * sizeof(char));
        strcpy(res , "0");
        return res;
    }

    char* res = (char*)malloc(numsSize * 12 * sizeof(char));
    res[0] = '\0';

    for(int i = 0; i < numsSize; i++){
        char temp[20];
        sprintf(temp , "%d" , nums[i]);
        strcat(res , temp);
    }
    return res;
}