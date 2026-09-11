class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        bool vis[1000] = {false};
        vector<int> result;

        for(int i = 0; i < digits.size(); i++){
            if(digits[i] == 0){
                continue;
            }
            for(int j = 0; j < digits.size(); j++){
                for(int k = 0; k < digits.size(); k++){
                    if(i == j || j == k || k == i){
                        continue;
                    }

                    if(digits[k] % 2 != 0){
                        continue;
                    }

                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(!vis[x]){
                        vis[x] = true;
                        result.push_back(x);
                    }
                }
            }
        }
        sort(result.begin() , result.end());
        return result;
    }
};