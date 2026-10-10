class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // 1------------------------------------------------------------------1
        // long long k = (long long)k1 + k2;
        // int n = nums1.size();

        // for(int i = 0; i < n; i++){
        //     nums1[i] = abs(nums1[i] - nums2[i]);
        // }

        // if(accumulate(nums1.begin() , nums1.end() , 0LL) <= k){
        //     return 0;
        // }

        // sort(nums1.begin() , nums1.end() , greater<int>());
        // nums1.push_back(0);
        // for(int i = 1; i <= n; i++){
        //     long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
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

        int n = nums1.size();
        long long ans = 0;
        long long k = (long long)k1 + k2;
        int maxDiff = 0;
        int res = 0;

        for(int i = 0; i < n; i++){
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff , nums1[i]);
        }

        int l = 0;
        int r = maxDiff;
        auto check = [&](int mid) -> bool{
            long long sum = 0;
            for(int num : nums1){
                sum += num > mid ? num - mid : 0;
            }
            return sum <= k;
        };

        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                r = mid - 1;
                res = mid;
            }else{
                l = mid + 1;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums1[i] > res){
                k -= (nums1[i] - res);
            }
        }

        sort(nums1.begin() , nums1.end() , greater<int>());
        for(int num : nums1){
            long long diff = res >= num ? num : res;
            if(k && diff){
                diff--;
                k--;
            }
            ans += diff * diff;
        }
        return ans;
    }
};