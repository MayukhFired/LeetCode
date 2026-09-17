class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int , int> pos;
        pos[0] = -1;
        int n = arr.size();
        int s = 0;
        int ans = n + 1;
        int minLen = n;
        for(int i = 0; i < n; i++){
            s += arr[i];
            if(pos.count(s - target)){
                int j = pos[s - target];
                int length = i - j;
                ans = min(ans , length + (j == -1 ? n : arr[j]));
                minLen = min(minLen , length);
            }
            arr[i] = minLen;
            pos[s] = i;
        }
        return ans == n + 1 ? -1 : ans;
    }
};