void dfs(int city , int** isConnected , int n , bool* visited){
    visited[city] = true;
    for(int neighbour = 0; neighbour < n; neighbour++){
        if(isConnected[city][neighbour] == 1 && !visited[neighbour]){
            dfs(neighbour , isConnected , n , visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    int provinces = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i , isConnected , n , visited);
            provinces++;
        }
    }
    return provinces;
}