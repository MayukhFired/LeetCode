#define Max(a , b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    if(heightsSize == 0){
        return 0;
    }

    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for(int i = 0; i <= heightsSize; i++){
        int curr_height = (i == heightsSize) ? 0 : heights[i];

        while(top >= 0 && heights[stack[top]] >= curr_height){
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            maxArea = Max(maxArea , height * width);
        }
        stack[++top] = i;
    }
    free(stack);
    return maxArea;
}