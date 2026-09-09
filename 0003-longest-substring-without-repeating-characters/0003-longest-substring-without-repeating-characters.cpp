class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }

        int last_seen[128];
        memset(last_seen , -1 , sizeof(last_seen));

        int max_len = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            char curr_char = s[right];

            if(last_seen[curr_char] >= left){
                left = last_seen[curr_char] + 1;
            }

            last_seen[curr_char] = right;

            int curr_size = right - left + 1;
            max_len = max(max_len , curr_size);
        }
        return max_len;
    }
};