typedef struct{
    int cost;
    int idx;
} Worker;

bool isSmaller(Worker a , Worker b){
    if(a.cost != b.cost){
        return a.cost < b.cost;
    }

    return a.idx < b.idx;
}

void swap(Worker* a , Worker* b){
    Worker temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(Worker* heap , int* heapSize , Worker val){
    heap[*heapSize] = val;
    int i = *heapSize;
    (*heapSize)++;

    while(i > 0 && isSmaller(heap[i] , heap[(i - 1) / 2])){
        swap(&heap[i] , &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Worker heapPop(Worker* heap , int* heapSize){
    Worker popped = heap[0];
    (*heapSize)--;
    heap[0] = heap[*heapSize];
    int i = 0;

    while(2 * i + 1 < *heapSize){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if(right < *heapSize && isSmaller(heap[right] , heap[left])){
            smallest = right;
        }

        if(isSmaller(heap[i] , heap[smallest]) || (heap[i].cost == heap[smallest].cost && heap[i].idx == heap[smallest].idx)){
            break;
        }

        swap(&heap[i] , &heap[smallest]);
        i = smallest;
    }
    return popped;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    int n = costsSize;
    Worker* head = (Worker*)malloc((candidates + 1) * sizeof(Worker));
    Worker* tail = (Worker*)malloc((candidates + 1) * sizeof(Worker));
    int headSize = 0;
    int tailSize = 0;

    int i = 0;
    int j = n - 1;
    long long total_cost = 0;

    for(int round = 0; round < k; round++){
        while(headSize < candidates && i <= j){
            Worker w = {costs[i] , i};
            heapPush(head , &headSize , w);
            i++;
        }

        while(tailSize < candidates && i <= j){
            Worker w = {costs[j] , j};
            heapPush(tail , &tailSize, w);
            j--;
        }

        if(headSize > 0 && tailSize > 0){
            if(isSmaller(head[0] , tail[0])){
                Worker picked = heapPop(head , &headSize);
                total_cost += picked.cost;
            }else{
                Worker picked = heapPop(tail , &tailSize);
                total_cost += picked.cost;
            }
        }else if(headSize > 0){
            Worker picked = heapPop(head , &headSize);
            total_cost += picked.cost;
        }else if(tailSize > 0){
            Worker picked = heapPop(tail , &tailSize);
            total_cost += picked.cost;
        }
    }

    return total_cost;
}