bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize , sizeof(bool));
    int* stack = (int*)malloc(roomsSize * 2000 * sizeof(int));
    int top = -1;
    stack[++top] = 0;
    int visitedCount = 0;
    while(top >= 0){
        int curr = stack[top--];
        if(!visited[curr]){
            visited[curr] = true;
            visitedCount++;
            for(int i = 0; i < roomsColSize[curr]; i++){
                int key = rooms[curr][i];
                if(!visited[key]){
                    stack[++top] = key;
                }
            }
        }
    }
    free(visited);
    free(stack);
    return visitedCount == roomsSize;
}