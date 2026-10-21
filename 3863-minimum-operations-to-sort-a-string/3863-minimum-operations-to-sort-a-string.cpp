class Solution {
public:
    int minOperations(string s) {
        char mx = 'a';
        char mn = 'z';
        int n = s.length();

        for(int i = 0; i < n; i++){
            mn = min(mn , s[i]);
            mx = max(mx , s[i]);
        }

        if(ranges::is_sorted(s)){
            return 0;
        }
        if(n == 2){
            return -1;
        }
        if(s[0] == mn || s[n - 1] == mx){
            return 1;
        }
        for(int i = 1; i < n - 1; i++){
            if(s[i] == mn || s[i] == mx){
                return 2;
            }
        }
        return 3;
    }
};