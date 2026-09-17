// typedef struct{
//     int id;
//     int pos;
//     UT_hash_handle hh;
// }HashEntry;

// int minSumOfLengths(int* arr, int arrSize, int target) {
//     int n = arrSize;
//     int s = 0;
//     int ans = n + 1;
//     int minLen = n;
//     HashEntry *prefixes = NULL , *entry , *tmp;

//     entry = malloc(sizeof(HashEntry));
//     entry->id = 0;
//     entry->pos = -1;
//     HASH_ADD_INT(prefixes , id , entry);

//     for(int i = 0; i < n; i++){
//         s += arr[i];
//         int key = s - target;
//         HASH_FIND_INT(prefixes , &key , entry);
//         if(entry != NULL){
//             int j = entry->pos;
//             int length = i - j;
//             int prev = j == -1 ? n : arr[j];
//             if(length + prev < ans){
//                 ans = length + prev;
//             }
//             if(length < minLen){
//                 minLen = length;
//             }
//         }
//         arr[i] = minLen;
//         HASH_FIND_INT(prefixes , &s , entry);
//         if(entry == NULL){
//             entry = malloc(sizeof(HashEntry));
//             entry->id = s;
//             HASH_ADD_INT(prefixes , id , entry);
//         }
//         entry->pos = i;
//     }
//     HASH_ITER(hh , prefixes , entry , tmp){
//         HASH_DEL(prefixes , entry);
//         free(entry);
//     }

//     return ans == n + 1 ? -1 : ans;
// }

#define Min(a , b) ((a) < (b) ? (a) : (b))

int minSumOfLengths(int* arr, int arrSize, int target){
    int n = arrSize;

    int* min_len = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        min_len[i] = n + 1;
    }

    int left = 0;
    int current_sum = 0;
    int min_total_sum = n + 1;
    int curr_min_len = n + 1;

    for(int right = 0; right < n; right++){
        current_sum += arr[right];

        while(current_sum > target && left <= right){
            current_sum -= arr[left];
            left++;
        }
        if(current_sum == target){
            int curr_len = right - left + 1;

            if(left > 0 && min_len[left - 1] <= n){
                min_total_sum = Min(min_total_sum , curr_len + min_len[left - 1]);
            }
            curr_min_len = Min(curr_min_len , curr_len);
        }
        min_len[right] = curr_min_len;
    }
    free(min_len);
    return min_total_sum > n ? -1 : min_total_sum;
}