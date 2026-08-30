typedef struct Edge {
    int to;
    int cost;
    struct Edge* next;
}Edge;

void dfs(int city , Edge** adj , bool* visited , int* change_count){
    visited[city] = true;
    Edge* curr = adj[city];
    while(curr != NULL){
        if(!visited[curr->to]){
            *change_count += curr->cost;
            dfs(curr->to , adj , visited , change_count);
        }
        curr = curr->next;
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    Edge** adj = (Edge**)calloc(n , sizeof(Edge*));
    for(int i = 0; i < connectionsSize; i++){
        int u = connections[i][0];
        int v = connections[i][1];

        Edge* e1 = (Edge*)malloc(sizeof(Edge));
        e1->to = v;
        e1->cost = 1;
        e1->next = adj[u];
        adj[u] = e1;

        Edge* e2 = (Edge*)malloc(sizeof(Edge));
        e2->to = u;
        e2->cost = 0;
        e2->next = adj[v];
        adj[v] = e2;
    }

    bool* visited = (bool*)calloc(n , sizeof(bool));
    int change_count = 0;
    dfs(0 , adj , visited , &change_count);
    for(int i = 0; i < n; i++){
        Edge* curr = adj[i];
        while(curr != NULL){
            Edge* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);
    free(visited);
    return change_count;
}