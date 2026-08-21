1long long gcd(long long a , long long b){
2    while(b != 0){
3        long long temp = b;
4        b = a % b;
5        a = temp;
6    }
7    return a;
8}
9
10long long lcm(long long a , long long b){
11    if(a == 0 || b == 0){
12        return 0;
13    }
14    return (a / gcd(a , b)) * b;
15}
16
17typedef struct{
18    long long lcm_val;
19    int sign;
20}SubsetLcm;
21
22long long count_amounts(long long max_val , SubsetLcm* subsets , int total_subsets){
23    long long total_count = 0;
24    for(int i = 0; i < total_subsets; i++){
25        total_count += subsets[i].sign * (max_val / subsets[i].lcm_val);
26    }
27    return total_count;
28}
29
30long long findKthSmallest(int* coins, int coinsSize, int k) {
31    int total_subsets = (1 << coinsSize) - 1;
32    SubsetLcm subsets[total_subsets];
33    int total_idx = 0;
34    long long min_coin = coins[0];
35    for(int i = 1; i < coinsSize; i++){
36        if(coins[i] < min_coin){
37            min_coin = coins[i];
38        }
39    }
40
41    for(int i = 1; i <= total_subsets; i++){
42        long long current_lcm = 1;
43        int count = 0;
44        for(int j = 0; j < coinsSize; j++){
45            if((i >> j) & 1){
46                count++;
47                current_lcm = lcm(current_lcm , coins[j]);
48            }
49        }
50        subsets[total_idx].lcm_val = current_lcm;
51        subsets[total_idx].sign = (count % 2 == 1) ? 1 : -1;
52        total_idx++;
53    }
54
55    long long low = 1;
56    long long high = (long long)k * min_coin;
57    long long ans = high;
58
59    while(low <= high){
60        long long mid = low + (high - low) / 2;
61        if(count_amounts(mid , subsets , total_subsets) >= k){
62            ans = mid;
63            high = mid - 1;
64        }else{
65            low = mid + 1;
66        }
67    }
68    return ans;
69}