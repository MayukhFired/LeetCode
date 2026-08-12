
#define Max_calls 10001

typedef struct {
    int queue[Max_calls];
    int head;
    int tail;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->queue[obj->tail] = t;
    obj->tail = (obj->tail + 1) % Max_calls;

    while(obj->head != obj->tail && obj->queue[obj->head] < t- 3000){
        obj->head = (obj->head + 1) % Max_calls;
    }

    if(obj->tail >= obj->head){
        return obj->tail - obj->head;
    }else{
        return Max_calls - (obj->head - obj->tail);
    }
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/