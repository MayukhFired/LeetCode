/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODES 40

int get_id(char* str , char nodes[MAX_NODES][6] , int* node_count){
    for(int i = 0; i < *node_count; i++){
        if(strcmp(nodes[i] , str) == 0) return i;
    }
    strcpy(nodes[*node_count] , str);
    return (*node_count)++;
}

double dfs(int curr , int target , double graph[MAX_NODES][MAX_NODES] , bool visited[MAX_NODES] , int node_count){
    if(curr == target){
        return 1.0;
    }
    visited[curr] = true;

    for(int i = 0; i < node_count; i++){
        if(graph[curr][i] != 0.0 && !visited[i]){
            double product = dfs(i , target , graph , visited , node_count);
            if(product != -1.0){
                return graph[curr][i] * product;
            }
        }
    }
    return -1.0;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    char nodes[MAX_NODES][6];
    int node_count = 0;
    double graph[MAX_NODES][MAX_NODES];
    memset(graph , 0 , sizeof(graph));

    for(int i = 0; i < equationsSize; i++){
        int u = get_id(equations[i][0] , nodes , &node_count);
        int v = get_id(equations[i][1] , nodes , &node_count);
        graph[u][v] = values[i];
        graph[v][u] = 1.0 / values[i];
    }

    double* results = (double*)malloc(queriesSize * sizeof(double));
    *returnSize = queriesSize;

    for(int i = 0; i < queriesSize; i++){
        int u = -1;
        int v = -1;
        for(int j = 0; j < node_count; j++){
            if(strcmp(nodes[j] , queries[i][0]) == 0) u = j;
            if(strcmp(nodes[j] , queries[i][1]) == 0) v = j;
        }
        if(u == -1 || v == -1){
            results[i] = -1.0;
        }else{
            bool visited[MAX_NODES] = {false};
            results[i] = dfs(u , v , graph , visited , node_count);
        }
    }
    return results;
}