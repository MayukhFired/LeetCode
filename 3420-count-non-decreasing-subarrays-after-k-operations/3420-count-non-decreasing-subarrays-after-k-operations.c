// 1---------------------------------------------------------------------------1
// #define MIN_QUEUE_SIZE 64

// typedef struct Element {
//     int data[2];
// }Element;

// typedef bool (*compare)(const void* , const void*);

// typedef struct PriorityQueue {
//     Element* arr;
//     int capacity;
//     int queueSize;
//     compare lessFunc;
// } PriorityQueue;

// Element* createElement(int x , int y){
//     Element* obj = (Element*)malloc(sizeof(Element));
//     obj->data[0] = x;
//     obj->data[1] = y;
//     return obj;
// }

// static bool greater(const void* a , const void* b){
//     Element* e1 = (Element*)a;
//     Element* e2 = (Element*)b;
//     return e1->data[0] < e2->data[0];
// }

// static void memSwap(void* m1 , void* m2 , size_t size){
//     unsigned char* a = (unsigned char*)m1;
//     unsigned char* b = (unsigned char*)m2;

//     while(size--){
//         unsigned char tmp = *a;
//         *a++ = *b;
//         *b++ = tmp;
//     }
// }

// static void swap(Element* arr , int i , int j){
//     memSwap(&arr[i] , & arr[j] , sizeof(Element));
// }

// static void down(Element* arr , int size , int i , compare cmpFunc){
//     for(int k = 2 * i + 1; k < size; k = 2 * k + 1){
//         if(k + 1 < size && cmpFunc(&arr[k] , &arr[k + 1])){
//             k++;
//         }
//         if(cmpFunc(&arr[k] , &arr[(k - 1) / 2])){
//             break;
//         }
//         swap(arr , k , (k - 1) / 2);
//     }
// }

// PriorityQueue* createPriorityQueue(compare cmpFunc){
//     PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
//     obj->capacity = MIN_QUEUE_SIZE;
//     obj->arr = (Element*)malloc(MIN_QUEUE_SIZE * sizeof(Element));
//     obj->queueSize = 0;
//     obj->lessFunc = cmpFunc;
//     return obj;
// }

// void heapify(PriorityQueue* obj){
//     for(int i = obj->queueSize / 2 - 1; i >= 0; i--){
//         down(obj->arr , obj->queueSize , i , obj->lessFunc);
//     }
// }

// void enQueue(PriorityQueue* obj , Element* e){
//     if(obj->queueSize == obj->capacity){
//         obj->capacity *= 2;
//         obj->arr = realloc(obj->arr , obj->capacity *sizeof(Element));
//     }

//     memcpy(&obj->arr[obj->queueSize] , e , sizeof(Element));

//     for(int i = obj->queueSize; i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2] , &obj->arr[i]); i = (i - 1) / 2){
//         swap(obj->arr , i , (i - 1) / 2);
//     }
//     obj->queueSize++;
// }

// Element* deQueue(PriorityQueue* obj){
//     swap(obj->arr , 0 , obj->queueSize - 1);
//     down(obj->arr , obj->queueSize - 1 , 0 , obj->lessFunc);
//     Element* e = &obj->arr[obj->queueSize - 1];
//     obj->queueSize--;
//     return e;
// }

// bool isEmpty(const PriorityQueue* obj){
//     return obj->queueSize == 0;
// }

// Element* front(const PriorityQueue* obj){
//     if(obj->queueSize == 0){
//         return NULL;
//     }else{
//         return &obj->arr[0];
//     }
// }

// void clear(PriorityQueue* obj){
//     obj->queueSize = 0;
// }

// int size(const PriorityQueue* obj){
//     return obj->queueSize;
// }

// void freeQueue(PriorityQueue* obj){
//     free(obj->arr);
//     free(obj);
// }

// long long countNonDecreasingSubarrays(int* nums, int numsSize, int k) {
//     int n = numsSize;
//     long long ans = 0;
//     long long operations = 0;

//     PriorityQueue* q = createPriorityQueue(greater);
//     int** cnt = (int**)malloc(n * sizeof(int*));
//     int* cntSize = (int*)calloc(n , sizeof(int));
//     int* cntCap = (int*)calloc(n , sizeof(int));
//     for(int i = 0; i < n; i++){
//         cnt[i] = (int*)malloc(4 * sizeof(int));
//         cntCap[i] = 4;
//     }

//     int* pos = (int*)malloc(n * sizeof(int));
//     for(int i = 0; i < n; i++){
//         pos[i] = n;
//     }
//     int* st = (int*)malloc(n * sizeof(int));
//     int top = 0;
//     int left = 0;

//     for(int right = 0; right < n; right++){
//         while(top > 0 && nums[right] >= nums[st[top - 1]]){
//             pos[st[top - 1]] = right;
//             top--;
//         }

//         if(top > 0){
//             int t = st[top - 1];
//             if(cntSize[t] == cntCap[t]){
//                 cntCap[t] *= 2;
//                 cnt[t] = (int*)realloc(cnt[t] , sizeof(int) * cntCap[t]);
//             }
//             cnt[t][cntSize[t]++] = right;
//         }
//         st[top++] = right;

//         Element* e = createElement(nums[right] , right);
//         enQueue(q , e);
//         free(e);
//         int diff = front(q)->data[0] - nums[right];
//         if(diff > 0){
//             operations += diff;
//         }

//         while(operations > k){
//             for(int j = 0; j < cntSize[left]; j++){
//                 int i = cnt[left][j];
//                 int pr = pos[i] < right + 1 ? pos[i] : right + 1;
//                 operations -= (long long)(nums[left] - nums[i]) * (pr - i);
//             }
//             left++;
//         }

//         while(!isEmpty(q) && front(q)->data[1] < left){
//             deQueue(q);
//         }

//         ans += right - left + 1;
//     }

//     for(int i = 0; i < n; i++){
//         free(cnt[i]);
//     }

//     free(cnt);
//     free(cntCap);
//     free(cntSize);
//     free(pos);
//     free(st);
//     freeQueue(q);

//     return ans;
// }
// 1-------------------------------------------------------------------------------------1

long long countNonDecreasingSubarrays(int* nums, int numsSize, int k){
    long long total_subarrays = 0;
    long long current_ops = 0;
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int head = 0;
    int tail = 0;
    int right = numsSize - 1;

    for(int left = numsSize - 1; left >= 0; left--){
        int current_element = nums[left];
        while(tail > head && nums[deque[tail - 1]] < current_element){
            int pop_idx = deque[tail - 1];
            tail--;

            int next_bound = (tail > head) ? deque[tail - 1] : right + 1;
            current_ops += (long long)(current_element - nums[pop_idx]) * (next_bound - pop_idx);
        }
        deque[tail++] = left;

        while(current_ops > k){
            int max_idx = deque[head];
            current_ops -= (long long)(nums[max_idx] - nums[right]);
            if(deque[head] == right){
                head++;
            }
            right--;
        }
        total_subarrays += (long long)(right - left + 1);
    }

    free(deque);
    return total_subarrays;
}