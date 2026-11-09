/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    long long free_time;
    int server_id;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc((capacity + 1) * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a , HeapNode* b){
    HeapNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(MinHeap* heap , long long free_time , int server_id){
    heap->size++;
    int i = heap->size;
    heap->data[i].free_time = free_time;
    heap->data[i].server_id = server_id;

    while(i > 1 && heap->data[i].free_time < heap->data[i/2].free_time){
        swap(&heap->data[i] , &heap->data[i/2]);
        i /= 2;
    }
}

HeapNode top(MinHeap* heap){
    return heap->data[1];
}

void pop(MinHeap* heap){
    if(heap->size == 0){
        return;
    }
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    int i = 1;

    while(2 * i <= heap->size){
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = left;

        if(right <= heap->size && heap->data[right].free_time < heap->data[left].free_time){
            smallest = right;
        }

        if(heap->data[i].free_time <= heap->data[smallest].free_time){
            break;
        }

        swap(&heap->data[i] , &heap->data[smallest]);
        i = smallest;
    }
}

void updateSet(int* tree , int node , int start , int end , int idx , int val){
    if(start == end){
        tree[node] = val;
        return;
    }

    int mid = start + (end - start) / 2;
    if(idx <= mid){
        updateSet(tree , node * 2 , start , mid , idx , val);
    }else{
        updateSet(tree , 2 * node + 1 , mid + 1 , end , idx , val);
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int querySet(int* tree , int node , int start , int end , int target){
    if(tree[node] == 0 || end < target){
        return -1;
    }
    if(start == end){
        return start;
    }

    int mid = start + (end - start) / 2;
    int res = querySet(tree , 2 * node , start , mid , target);
    if(res != -1) return res;
    return querySet(tree , 2 * node + 1 , mid + 1 , end , target);
}

int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize) {
    int* count = (int*)calloc(k , sizeof(int));
    int* segmentTree = (int*)calloc(4 * k , sizeof(int));
    for(int i = 0; i < k; i++){
        updateSet(segmentTree , 1 , 0 , k - 1 , i , 1);
    }

    MinHeap* busy = createHeap(k);

    for(int i = 0; i < arrivalSize; i++){
        long long curr_time = arrival[i];
        while(busy->size > 0 && top(busy).free_time <= curr_time){
            HeapNode node = top(busy);
            pop(busy);
            updateSet(segmentTree , 1 , 0 , k - 1 , node.server_id , 1);
        }

        int target = i % k;
        int server_id = querySet(segmentTree , 1 , 0 , k - 1 , target);
        if(server_id == -1){
            server_id = querySet(segmentTree , 1 , 0 , k - 1 , 0);
        } 
        if(server_id == -1) continue;

        updateSet(segmentTree , 1 , 0 , k - 1 , server_id , 0);
        push(busy , curr_time + load[i] , server_id);
        count[server_id]++;
    }

    int max_handled = 0;
    for(int i = 0; i < k; i++){
        if(count[i] > max_handled){
            max_handled = count[i];
        }
    }

    int* res = (int*)malloc(k * sizeof(int));
    int res_idx = 0;
    for(int i = 0; i < k; i++){
        if(count[i] == max_handled){
            res[res_idx++] = i;
        }
    }

    *returnSize = res_idx;
    free(busy->data);
    free(busy);
    free(count);
    free(segmentTree);

    return res;
}