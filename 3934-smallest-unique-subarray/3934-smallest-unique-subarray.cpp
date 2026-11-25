using ll = long long;
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
    // 1-----------------------------------------------------------------------------1
        // int n = (int)nums.size();
        // vector<int> sa(n) , rank(nums.begin() , nums.end());
        // vector<int> nextRank(n);
        // iota(sa.begin() , sa.end() , 0);
        // int maxRank = *max_element(nums.begin() , nums.end());
        // vector<int> temp(n) , cnt(max(n + 1 , maxRank + 2));

        // auto counting_sort = [&](auto get_key){
        //     fill(cnt.begin() , cnt.end() , 0);
        //     for(int i : sa){
        //         cnt[get_key(i)]++;
        //     }

        //     for(int i = 1; i <= maxRank + 1; i++){
        //         cnt[i] += cnt[i - 1];
        //     }

        //     for(int p = n - 1; p>= 0; p--){
        //         int i = sa[p];
        //         temp[--cnt[get_key(i)]] = i;
        //     }

        //     sa.swap(temp);
        // };

        // for(int k = 1; k < n; k <<= 1){
        //     auto get_rank = [&](int i) -> pair<int , int> {
        //         return {rank[i] , i + k < n ? rank[i + k] : -1};
        //     };

        //     counting_sort([&](int i){
        //         return get_rank(i).second + 1;
        //     });
        //     counting_sort([&](int i){
        //         return get_rank(i).first + 1;
        //     });
        //     nextRank[sa[0]] = 0;

        //     for(int i = 1; i < n; i++){
        //         auto rx = get_rank(sa[i - 1]) , ry = get_rank(sa[i]);
        //         nextRank[sa[i]] = nextRank[sa[i - 1]] + (rx != ry);
        //     }

        //     rank.swap(nextRank);
        //     maxRank = rank[sa.back()];

        //     if(maxRank == n - 1){
        //         break;
        //     }
        // }

        // vector<int> pos(n) , lcp(n , 0);

        // for(int i = 0; i < n; i++){
        //     pos[sa[i]] = i;
        // }

        // int h = 0;
        // for(int i = 0; i < n; i++){
        //     if(pos[i] == 0){
        //         h = 0;
        //         continue;
        //     }

        //     int j = sa[pos[i] - 1];
        //     while(i + h < n && j + h < n && nums[i + h] == nums[j + h]){
        //         h++;
        //     }

        //     lcp[pos[i]] = h;
        //     if(h > 0){
        //         h--;
        //     }
        // }

        // int ans = n;
        // for(int i = 0; i < n; i++){
        //     int next = (i + 1 < n ? lcp[i + 1] : 0);
        //     int need = max(lcp[i] , next) + 1;
        //     if(sa[i] + need - 1 < n) {
        //         ans = min(need , ans);
        //     }
        // }

        // return ans;
    // 1--------------------------------------------------------------------------1
        const ll MOD = 1000000007LL;
        const ll BASE = 911382323LL;

        int n = (int)nums.size();
        vector<ll> h(n + 1);
        vector<ll> p(n + 1);
        p[0] = 1;

        for(int i = 0; i < n; i++){
            h[i + 1] = (h[i] * BASE + nums[i]) % MOD;
            p[i + 1] = p[i] * BASE % MOD;
        }

        auto check = [&](int len) {
            unordered_map<ll , int> cnt;
            for(int l = 0; l + len <= n; l++){
                int r = l + len;
                ll key = (h[r] - h[l] * p[len] % MOD + MOD) % MOD;
                cnt[key]++;
            }

            for(auto& [key , times] : cnt){
                if(times == 1){
                    return true;
                }
            }
            return false;
        };

        int low = 1;
        int high = n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(check(mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};