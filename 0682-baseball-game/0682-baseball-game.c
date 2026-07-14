int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int top = -1;

    for(int i = 0; i < operationsSize; i++){
        if(operations[i][0] == '+'){
            stack[top + 1] = stack[top] + stack[top - 1];
            top++;
        }else if(operations[i][0] == 'D'){
            stack[top + 1] = 2 * stack[top];
            top++;
        }else if(operations[i][0] == 'C'){
            top--;
        }else{
            stack[++top] = atoi(operations[i]); 
        }
    }

    int totalSum = 0;
    for(int i = 0; i <= top; i++){
        totalSum += stack[i];
    }

    free(stack);
    return totalSum;
}