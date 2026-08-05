/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int* graphSize = (int*)calloc(n , sizeof(int));
    int* graphCap = (int*)calloc(n , sizeof(int));
    int** graph = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        graphCap[i] = 2;
        graph[i] = (int*)malloc(graphCap[i] * sizeof(int));
    }
    for(int i = 0; i < invocationsSize; i++){
        int u = invocations[i][0];
        int v = invocations[i][1];

        if(graphSize[u] >= graphCap[u]){
            graphCap[u] *= 2;
            graph[u] = (int*)realloc(graph[u] , graphCap[u] * sizeof(int));
        }
        graph[u][graphSize[u]++] = v;
    }
    bool* sus = (bool*)calloc(n , sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0;
    int tail = 0;
    sus[k] = true;
    queue[tail++] = k;
    while(head < tail){
        int curr = queue[head++];
        for(int i = 0; i < graphSize[curr]; i++){
            int neighbour = graph[curr][i];
            if(!sus[neighbour]){
                sus[neighbour] = true;
                queue[tail++] = neighbour;
            }
        }
    }
    bool canRemove = true;
    for(int i = 0; i < invocationsSize; i++){
        int u = invocations[i][0];
        int v = invocations[i][1];
        if(!sus[u] && sus[v]){
            canRemove = false;
            break;
        }
    }
    int* result = NULL;
    int count = 0;
    if(!canRemove){
        result = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n ; i++){
            result[i] = i;
        }
        *returnSize = n;
    }else{
        for(int i = 0; i < n; i++){
            if(!sus[i]){
                count++;
            }
        }
        result = (int*)malloc(count * sizeof(int));
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(!sus[i]){
                result[idx++] = i;
            }
        }
        *returnSize = count;
    }
    for(int i = 0; i < n; i++){
        free(graph[i]);
    }

    free(graph);
    free(graphSize);
    free(graphCap);
    free(sus);
    free(queue);
    return result;
}