/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a , const void* b){
    return(*(int*)b - *(int*)a);
}

bool binarySearch(int* arr , int arrSize , int target){
    int left = 0;
    int right = arrSize - 1;
    while(left <= right){
        int mid = left+ (right - left) / 2;
        if(arr[mid] == target){
            return true;
        }else if(arr[mid] > target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    qsort(nums1 , nums1Size , sizeof(int) , compare);
    qsort(nums2 , nums2Size , sizeof(int) , compare);

    int** result = (int**)malloc(2 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    int* dist1 = (int*)malloc(nums1Size * sizeof(int));
    int* dist2 = (int*)malloc(nums2Size * sizeof(int));

    int len1 = 0;
    int len2 = 0;
    for(int i = 0; i < nums1Size; i++){
        if(i > 0 && nums1[i] == nums1[i - 1]){
            continue;
        }
        if(!binarySearch(nums2 , nums2Size , nums1[i])){
            dist1[len1++] = nums1[i];
        }
    }

    for(int i = 0; i < nums2Size; i++){
        if(i > 0 && nums2[i] == nums2[i - 1]){
            continue;
        }
        if(!binarySearch(nums1 , nums1Size , nums2[i])){
            dist2[len2++] = nums2[i];
        }
    }

    result[0] = (int*)realloc(dist1 , len1 * sizeof(int));
    (*returnColumnSizes)[0] = len1;

    result[1] = (int*)realloc(dist2 , len2 * sizeof(int));
    (*returnColumnSizes)[1] = len2;

    return result;
}