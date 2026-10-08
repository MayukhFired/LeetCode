/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int* result = (int*)calloc(n , sizeof(int));
    *returnSize = n;

    int* stk = (int*)malloc(logsSize * sizeof(int));
    int top = -1;
    int prev_time = 0;

    for(int i = 0; i < logsSize; i++){
        int find_id;
        char status[10];
        int timestamp;

        sscanf(logs[i] , "%d:%[^:]:%d" , &find_id , status , &timestamp);

        if(strcmp(status , "start") == 0){
            if(top != -1){
                result[stk[top]] += timestamp - prev_time;
            }

            stk[++top] = find_id;
            prev_time = timestamp;
        }else{
            int popped_id = stk[top--];
            result[popped_id] += timestamp - prev_time + 1;
            prev_time = timestamp + 1;
        }
    }
    free(stk);
    return result;
}