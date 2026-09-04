class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minIndex(n);
        int minElement = INT_MAX;

        for(int i = n - 1; i >= 0; i--){
            minElement = min(minElement , nums[i]);
            minIndex[i] = minElement;
        }

        int maxElement = INT_MIN;
        for(int i = 0; i < n; i++){
            maxElement = max(maxElement , nums[i]);

            if(maxElement - minIndex[i] <= k){
                return i;
            }
        }
        return -1;
    }
};