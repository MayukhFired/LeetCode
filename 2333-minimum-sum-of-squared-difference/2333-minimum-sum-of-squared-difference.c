#define Max(a , b) ((a) > (b) ? (a) : (b))
// This function also includes in the second approach
int compare(const void* a , const void* b){
    return (*(const int*)b - *(const int*)a);
}

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
    // 1---------------------------------------------------------1
    // long long k = (long long)k1 + k2;
    // int n = nums1Size;
    // long long sum = 0;

    // for(int i = 0; i < n; i++){
    //     nums1[i] = abs(nums1[i] - nums2[i]);
    //     sum += nums1[i];
    // }

    // if(sum <= k){
    //     return 0;
    // }

    // qsort(nums1 , n , sizeof(int) , compare);
    // for(int i = 1; i <= n; i++){
    //     int next = i < n ? nums1[i] : 0;
    //     long long cost = (long long)(nums1[i - 1] - next) * i;
    //     if(cost > k){
    //         long long q = k / i;
    //         long long r = k % i;
    //         long long hi = nums1[i - 1] - q;
    //         long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
    //         for(int j = i; j < n; j++){
    //             ans += (long long)nums1[j] * nums1[j];
    //         }
    //         return ans;
    //     }
    //     k -= cost;
    // }
    // return 0;
    // 1----------------------------------------------------------------------------1

    int n = nums1Size;
    long long k = (long long)k1 + k2;
    int maxDiff = 0;
    for(int i = 0; i < n; i++){
        nums1[i] = abs(nums1[i] - nums2[i]);
        maxDiff = Max(maxDiff , nums1[i]);
    }

    int l = 0;
    int r = maxDiff;
    int res = 0;

    while(l <= r){
        int mid = (l + r) >> 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums1[i] > mid ? nums1[i] - mid : 0;
        }

        if(sum <= k){
            r = mid - 1;
            res = mid;
        }else{
            l = mid + 1;
        }
    }

    for(int i = 0; i < n; i++){
        if(nums1[i] > res){
            k -= nums1[i] - res;
        }
    }

    qsort(nums1 , n , sizeof(int) , compare);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long diff = nums1[i] < res ? nums1[i] : res;
        if(k > 0 && diff > 0){
            diff--;
            k--;
        }
        ans += diff * diff;
    }
    return ans;
}