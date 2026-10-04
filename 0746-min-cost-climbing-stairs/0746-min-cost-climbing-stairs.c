#define Min(a , b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize) {
    int first = 0;
    int second = 0;

    for(int i = 0; i < costSize; i++){
        int next = cost[i] + Min(first , second);
        first = second;
        second = next;
    }

    return Min(first , second);
}