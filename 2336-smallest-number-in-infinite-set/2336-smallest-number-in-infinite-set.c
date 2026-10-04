#define Max 1001

typedef struct {
    int curr_smallest;
    bool is_present[Max];
} SmallestInfiniteSet;


SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    obj->curr_smallest = 1;

    for(int i = 0; i < Max; i++){
        obj->is_present[i] = true;
    }
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int popped_val = obj->curr_smallest;
    obj->is_present[popped_val] = false;
    int smallest = popped_val;

    while(smallest < Max && !obj->is_present[smallest]){
        smallest++;
    }

    obj->curr_smallest = smallest;
    return popped_val;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if(!obj->is_present[num]){
        obj->is_present[num] = true;

        if(num < obj->curr_smallest){
            obj->curr_smallest = num;
        }
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/