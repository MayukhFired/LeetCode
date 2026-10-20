int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}
// 1---------------------------------------------------------------1
// int kmp(int* nums1 , int n , int* nums2 , int m){
//     int* pi = (int*)calloc(m , sizeof(int));
//     int j = 0;

//     for(int i = 1; i < m; i++){
//         while(j > 0 && nums2[i] != nums2[j]){
//            j = pi[j - 1];
//         }
//         if(nums2[j] == nums2[i]){
//             j++;
//         }
//         pi[i] = j;
//     }

//     j = 0;
//     for(int i = 0; i < n; i++){
//         while(j > 0 && nums1[i] != nums2[j]){
//             j = pi[j - 1];
//         }
//         if(nums1[i] == nums2[j]){
//             j++;
//         }
//         if(j == m){
//             free(pi);
//             return 1;
//         }
//     }
//     free(pi);
//     return 0;
// }


// int check(int* nums1 , int len , int* nums2){
//     int* doubled = (int*)malloc(2 * len * sizeof(int));
//     memcpy(doubled , nums1 , len* sizeof(int));
//     memcpy(doubled + len , nums1 , len * sizeof(int));
//     int res = kmp(doubled , 2 * len , nums2 , len);
//     free(doubled);
//     return res;
// }
// 1------------------------------------------------------------------1

bool check(int* nums1 , int len1 , int* nums2 , int len2){
    if(len1 != len2){
        return false;
    }
    int L = len1;

    for(int i = 0; i < L - 1; i++){
        if(nums1[i] > nums1[i + 1]){
            int* rotated = (int*)malloc(L * sizeof(int));
            memcpy(rotated , nums1 + i + 1 , (L - i - 1) * sizeof(int));
            memcpy(rotated + L - i - 1 , nums1 , (i + 1) * sizeof(int));
            bool res = (memcmp(rotated , nums2 , L * sizeof(int)) == 0);
            free(rotated);
            return res;
        }
    }
    return memcmp(nums1 , nums2 , L *sizeof(int)) == 0;
}

int sortableIntegers(int* nums, int numsSize) {
    int* fac = (int*)malloc(numsSize * sizeof(int));
    int facCount = 0;

    for(int x = 1; x * x <= numsSize; x++){
        if(numsSize % x == 0){
            fac[facCount++] = x;
            if(numsSize / x != x){
                fac[facCount++] = numsSize / x;
            }
        }
    }

    int* target = (int*)malloc(numsSize * sizeof(int));
    memcpy(target ,nums , numsSize * sizeof(int));
    qsort(target , numsSize , sizeof(int) , compare);
    int ans = 0;

    for(int i = 0; i < facCount; i++){
        int d = fac[i];
        int allGood = 1;

        for(int left = 0; left < numsSize; left += d){
            if(!check(nums + left , d  , target + left , d)){
                allGood = 0;
                break;
            }
        }
        if(allGood){
            ans += d;
        }
    }
    free(fac);
    free(target);
    return ans;
}