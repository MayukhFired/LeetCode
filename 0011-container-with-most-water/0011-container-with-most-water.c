#define Max(a , b)  (a > b ? a : b);
#define Min(a , b)  (a < b ? a : b);

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int current_water = 0;
    int result = 0;

    while(left <= right){
        current_water = (right - left) * Min(height[right] , height[left]);
        result = Max(result , current_water);

        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }

    return result;
}