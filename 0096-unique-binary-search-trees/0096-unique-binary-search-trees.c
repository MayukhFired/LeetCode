int numTrees(int n) {
    int* uniqueTrees = (int*)malloc((n + 1) * sizeof(int));
    for(int i = 0; i < n + 1; i++){
        uniqueTrees[i] = 1;
    }

    for(int nodes = 2; nodes <= n; nodes++){
        int total = 0;
        for(int root = 1; root <= nodes; root++){
            total += uniqueTrees[root - 1] * uniqueTrees[nodes - root];
        }
        uniqueTrees[nodes] = total;
    }
    int res = uniqueTrees[n];
    free(uniqueTrees);
    return res;
}