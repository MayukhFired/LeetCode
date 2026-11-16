int peakIndexInMountainArray(int* arr, int arrSize) {
    int l = 0;
    int r = arrSize - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(arr[mid] < arr[mid + 1]){
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    return l;
}