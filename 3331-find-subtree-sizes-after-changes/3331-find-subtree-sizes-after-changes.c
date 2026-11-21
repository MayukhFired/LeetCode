/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int u , int* parent , char* s , int* last , int* head , int* to , int* next) {
    int c = s[u] - 'a';
    int old = last[c];

    if(u != 0 && old != -1){
        parent[u] = old;
    }

    last[c] = u;
    for(int e = head[u]; e != -1; e = next[e]) {
        dfs(to[e] , parent , s , last , head , to , next);
    }

    last[c] = old;
}

int calculate(int u , int* ans , int* head , int* to , int* next) {
    ans[u] = 1;
    for(int e = head[u]; e != -1; e = next[e]) {
        ans[u] += calculate(to[e] , ans , head , to , next);
    }
    return ans[u];
}

int* findSubtreeSizes(int* parent, int parentSize, char* s, int* returnSize) {
    int n = parentSize;
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    int* head = (int*)malloc(n * sizeof(int));
    int* to = (int*)malloc(n * sizeof(int));
    int* next = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        head[i] = -1;
    }
    int edge_count = 0;

    for(int i = 1; i < n; i++){
        int u = parent[i];
        to[edge_count] = i;
        next[edge_count] = head[u];
        head[u] = edge_count++;
    }

    int last[26];
    for(int i = 0; i < 26; i++){
        last[i] = -1;
    }
    dfs(0 , parent , s , last , head , to , next);

    for(int i = 0 ;i < n; i++){
        head[i] = -1;
    }

    edge_count = 0;
    for(int i = 1; i < n; i++){
        int u = parent[i];
        to[edge_count] = i;
        next[edge_count] = head[u];
        head[u] = edge_count++;
    }

    calculate(0 , ans , head , to , next);

    free(head);
    free(to);
    free(next);

    return ans;
}