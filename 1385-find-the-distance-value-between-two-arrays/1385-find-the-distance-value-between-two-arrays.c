int compare(const void* a , const void* b){
    return (*(int*)a - *(int*)b);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
// 1---------------------------------------------------1
    // int count = 0;
    // for(int i = 0; i < arr1Size; i++){
    //     bool ok = true;
    //     for(int j = 0;j < arr2Size; j++){
    //         ok = ok && (abs(arr2[j] - arr1[i]) > d);
    //     }
    //     count += ok ? 1 : 0;
    // }
    // return count;
// 1-----------------------------------------------------1
    qsort(arr2 , arr2Size , sizeof(int) , compare);
    int count = 0;

    for(int i = 0; i < arr1Size; i++){
        int x = arr1[i];
        int left = 0;
        int right = arr2Size;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr2[mid] < x){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        int p = left;
        bool ok = true;
        if(p < arr2Size){
            ok = ok && (arr2[p] - x > d);
        }
        if(p - 1 >= 0 && p - 1 < arr2Size){
            ok = ok && (x - arr2[p - 1] > d);
        }
        count += ok ? 1 : 0;
    }
    return count;
}