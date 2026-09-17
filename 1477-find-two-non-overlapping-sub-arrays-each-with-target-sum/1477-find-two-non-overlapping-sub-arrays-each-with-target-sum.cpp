class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // unordered_map<int , int> pos;
        // pos[0] = -1;
        // int n = arr.size();
        // int s = 0;
        // int ans = n + 1;
        // int minLen = n;
        // for(int i = 0; i < n; i++){
        //     s += arr[i];
        //     if(pos.count(s - target)){
        //         int j = pos[s - target];
        //         int length = i - j;
        //         ans = min(ans , length + (j == -1 ? n : arr[j]));
        //         minLen = min(minLen , length);
        //     }
        //     arr[i] = minLen;
        //     pos[s] = i;
        // }
        // return ans == n + 1 ? -1 : ans;

        int n = arr.size();
        const int INF = n + 1;

        vector<int> min_len(n , INF);

        int left = 0;
        int curr_sum = 0;
        int min_total_sum = INF;
        int curr_min_len = INF;

        for(int right = 0; right < n; right++){
            curr_sum += arr[right];
            while(curr_sum > target && left <= right){
                curr_sum -= arr[left];
                left ++;
            }
            if(curr_sum == target){
                int curr_len = right - left + 1;

                if(left > 0 && min_len[left - 1] != INF){
                    min_total_sum = min(min_total_sum , curr_len + min_len[left - 1]);
                }
                curr_min_len = min(curr_min_len , curr_len);
            }
            min_len[right] = curr_min_len;
        }
        return min_total_sum == INF ? -1 : min_total_sum;
    }
};