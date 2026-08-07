/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int top = 0;
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    for(int i = 0; i < asteroidsSize; i++){
        int ast = asteroids[i];
        int des = 0;
        while(top > 0 && ast < 0 && stack[top - 1] > 0){
            if(stack[top - 1] < abs(ast)){
                top--;
                continue;
            }else if(stack[top - 1] == abs(ast)){
                top--;
            }
            des = 1;
            break;
        }
        if(des != 1){
            stack[top++] = ast;
        }
    }
    *returnSize = top;
    return stack;
}