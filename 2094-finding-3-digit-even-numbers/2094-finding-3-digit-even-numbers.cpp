class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // bool vis[1000] = {false};
        // vector<int> result;

        // for(int i = 0; i < digits.size(); i++){
        //     if(digits[i] == 0){
        //         continue;
        //     }
        //     for(int j = 0; j < digits.size(); j++){
        //         for(int k = 0; k < digits.size(); k++){
        //             if(i == j || j == k || k == i){
        //                 continue;
        //             }

        //             if(digits[k] % 2 != 0){
        //                 continue;
        //             }

        //             int x = digits[i] * 100 + digits[j] * 10 + digits[k];
        //             if(!vis[x]){
        //                 vis[x] = true;
        //                 result.push_back(x);
        //             }
        //         }
        //     }
        // }
        // sort(result.begin() , result.end());
        // return result;

        int count[10] = {0};
        for(int i = 0; i < digits.size(); i++){
            count[digits[i]]++;
        }

        vector<int> result;
        for(int num = 100; num <= 998; num += 2){
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            count[d1]--;
            count[d2]--;
            count[d3]--;

            if(count[d1] >= 0 && count[d2] >= 0 && count[d3] >= 0){
                result.push_back(num);
            }

            count[d1]++;
            count[d2]++;
            count[d3]++;
        }

        return result;
    }
};