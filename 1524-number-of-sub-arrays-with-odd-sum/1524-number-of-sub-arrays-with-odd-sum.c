int numOfSubarrays(int* arr, int arrSize) {
// 1---------------------------------------------------------1
    // const int MOD = 1e9 + 7;
    // int prefixSum = 0;
    // int oddCount = 0;
    // int evenCount = 1;
    // int count = 0;

    // for(int i = 0; i < arrSize; i++){
    //     prefixSum += arr[i];
    //     if(prefixSum % 2 == 0){
    //         count += oddCount;
    //         evenCount++;
    //     }else{
    //         count += evenCount;
    //         oddCount++;
    //     }
    //     count %= MOD;
    // }

    // return count;
// 1------------------------------------------------------1
    const int MOD = 1e9 + 7;
    long long oddCount = 0;
    int prefixSum = 0;

    for(int i = 0; i < arrSize; i++){
        prefixSum += arr[i];
        if(prefixSum % 2){
            oddCount++;
        }
    }

    oddCount += (arrSize - oddCount) * oddCount;

    return oddCount % MOD;
}