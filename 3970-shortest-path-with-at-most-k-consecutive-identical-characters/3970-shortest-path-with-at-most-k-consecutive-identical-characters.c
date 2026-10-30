typedef struct {
    long long d;
    int x , cnt;
} State;

typedef struct {
    State* data;
    int size , capacity;
} MinHeap;

static void headPush(MinHeap* h , State s){
    if(h->size == h->capacity){
        h->capacity = h->capacity ? h->capacity * 2 : 16;
        h->data = realloc(h->data , (size_t)h->capacity * sizeof(State));
    }

    int i = h->size++;
    while(i > 0 && h->data[(i - 1) / 2].d > s.d){
        h->data[i] = h->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->data[i] = s;
}

static State heapPop(MinHeap* h){
    State res = h->data[0];
    State last = h->data[--h->size];
    if(h->size == 0){
        return res;
    }

    int i = 0;
    while(i * 2 + 1 < h->size){
        int j = i * 2 + 1;
        if(j + 1 < h->size && h->data[j + 1].d < h->data[j].d){
            j++;
        }
        if(last.d <= h->data[j].d){
            break;
        }
        h->data[i] = h->data[j];
        i = j;
    }

    h->data[i] = last;
    return res;
}

int shortestPath(int n, int** edges, int edgesSize, int* edgesColSize, char* labels, int k) {
    int* head = malloc((size_t)n * sizeof(int));
    int* to = malloc((size_t)edgesSize * sizeof(int));
    int* weight = malloc((size_t)edgesSize * sizeof(int));
    int* next = malloc((size_t)edgesSize * sizeof(int));

    for(int i = 0; i < n; i++){
        head[i] = -1;
    }

    for(int i = 0; i < edgesSize; i++){
        int x = edges[i][0];
        to[i] = edges[i][1];
        weight[i] = edges[i][2];
        next[i] = head[x];
        head[x] = i;
    }

    size_t width = (size_t)k + 1;
    long long* dis = malloc((size_t)n * width * sizeof(long long));
    for(size_t i =0; i < (size_t)n * width; i++){
        dis[i] = LLONG_MAX;
    }

    MinHeap pq = {NULL , 0 , 0};
    dis[0 * width + 1] = 0;
    headPush(&pq , (State){0 , 0 , 1});
    int ans = -1;

    while(pq.size > 0){
        State curr = heapPop(&pq);
        long long d = curr.d;
        int x = curr.x , cnt = curr.cnt;

        if(d > dis[x * width + cnt]){
            continue;
        }
        if(x == n - 1){
            ans = (int)d;
            break;
        }

        for(int i = head[x]; i != -1; i = next[i]){
            int y = to[i] , w = weight[i];
            int newCnt = labels[x] == labels[y] ? cnt + 1 : 1;
            if(newCnt > k){
                continue;
            }
            long long nd = d + w;
            size_t idx = y * width + newCnt;
            if(nd < dis[idx]){
                dis[idx] = nd;
                headPush(&pq , (State){nd , y ,newCnt});
            }
        }
    }

    free(to);
    free(dis);
    free(head);
    free(next);
    free(weight);
    free(pq.data);
    return ans;
}