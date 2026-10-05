typedef struct{
    int n1;
    int n2;
} Pair;

int comparePairs(const void* a , const void* b){
    int valA = ((Pair*)a)->n2;
    int valB = ((Pair*)b)->n2;

    return (valB - valA);
}

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heappush(int* heap , int* heapSize , int val){
    heap[*heapSize] = val;
    int i = *heapSize;
    (*heapSize)++;

    while(i > 0 && heap[i] < heap[(i - 1) / 2]){
        swap(&heap[i] , &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int heappop(int* heap , int* heapSize){
    int popped = heap[0];
    (*heapSize)--;
    heap[0] = heap[*heapSize];

    int i = 0;

    while(2 * i + 1 < *heapSize){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if(right < *heapSize && heap[right] < heap[left]){
            smallest = right;
        }

        if(heap[i] <= heap[smallest]){
            break;
        }

        swap(&heap[i] , &heap[smallest]);
        i = smallest;
    }

    return popped;
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int n = nums1Size;
    Pair* pairs = (Pair*)malloc(n * sizeof(Pair));

    for(int i = 0; i < n; i++){
        pairs[i].n1 = nums1[i];
        pairs[i].n2 = nums2[i];
    }

    qsort(pairs , n , sizeof(Pair) , comparePairs);

    int* minHeap = (int*)malloc((k + 1) * sizeof(int));
    int heapSize = 0;

    long long curr_sum = 0;
    long long max_score = 0;

    for(int i = 0; i < n; i++){
        heappush(minHeap , &heapSize , pairs[i].n1);
        curr_sum += pairs[i].n1;

        if(heapSize > k){
            int removed = heappop(minHeap , &heapSize);
            curr_sum -= removed;
        }

        if(heapSize == k){
            long long temp = curr_sum * pairs[i].n2;
            if(temp > max_score){
                max_score = temp;
            }
        }
    }

    free(pairs);
    free(minHeap);

    return max_score;
}