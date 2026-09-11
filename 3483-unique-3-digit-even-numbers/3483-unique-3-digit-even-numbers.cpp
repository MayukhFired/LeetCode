class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        bool vis[1000] = {false};
        int n = digits.size();

        for(int i = 0; i < n; i++){
            if(digits[i] == 0){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                for(int k = 0; k < n; k++){
                    if(k == i || k == j || digits[k] % 2 != 0){
                        continue;
                    }
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(!vis[x]){
                        vis[x] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};