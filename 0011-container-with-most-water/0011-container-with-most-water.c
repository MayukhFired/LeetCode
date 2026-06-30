int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int ans = INT_MIN;

    while(left < right){
        if(height[left] < height[right]){
            int temp = (right - left) * height[left];
            ans = (ans > temp ? ans : temp);
            left++;
        }else{
            int temp = (right - left) * height[right];
            ans = (ans > temp ? ans : temp);
            right--;
        }
    }    
    return ans;
}