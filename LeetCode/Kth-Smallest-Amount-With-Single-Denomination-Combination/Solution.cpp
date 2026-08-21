1class Solution {
2private:
3    struct SubsetLcm{
4        long long lcm_val;
5        int sign;
6    };
7
8    long long count_amounts(long long max_val , const vector<SubsetLcm>& subsets){
9        long long total_count = 0;
10        for(const auto& subset : subsets){
11            total_count += subset.sign * (max_val / subset.lcm_val);
12        }
13        return total_count;
14    }
15public:
16    long long findKthSmallest(vector<int>& coins, int k) {
17        int coin_size = coins.size();
18        int total_subsets = (1 << coin_size) - 1;
19        vector<SubsetLcm> subsets;
20        subsets.reserve(total_subsets);
21        long long min_coin = *min_element(coins.begin() , coins.end());
22        long long high = k * min_coin;
23        for(int i = 1; i <= total_subsets; i++){
24            long long current_lcm = 1;
25            int count = 0;
26            bool overflowed = false;
27            for(int j = 0; j < coin_size; j++){
28                if((i >> j) & 1){
29                    count++;
30                    long long next_lcm = lcm(current_lcm , static_cast<long long>(coins[j]));
31                    if(next_lcm > high || next_lcm < 0){
32                        current_lcm = high + 1;
33                        overflowed = true;
34                        break;
35                    }
36                    current_lcm = next_lcm;
37                }
38            }
39            int sign = (count % 2 == 1) ? 1 : -1;
40            subsets.push_back({current_lcm , sign});
41        }
42
43        long long low = 1;
44        long long ans = high;
45        while(low <= high){
46            long long mid = low + (high - low) / 2;
47            if(count_amounts(mid , subsets) >= k){
48                ans = mid;
49                high = mid - 1;
50            }else{
51                low = mid + 1;
52            }
53        }
54        return ans;
55    }
56};