class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0;
        int prefixSum = 0;
        int oddCount = 0;
        int evenCount = 1;

        for(int num : arr){
            prefixSum += num;
            if(prefixSum % 2 == 0){
                count = (count + oddCount) % MOD;
                evenCount++;
            }else{
                count = (count + evenCount) % MOD;
                oddCount++;
            }
        }
        return count;
    }
};