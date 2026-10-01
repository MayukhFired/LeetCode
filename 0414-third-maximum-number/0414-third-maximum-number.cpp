class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin() , nums.end() , greater<int>());

        int elemCounted = 1;
        int prevElem = nums[0];

        for(int idx = 0; idx < nums.size(); idx++){
            if(nums[idx] != prevElem){
                elemCounted += 1;
                prevElem = nums[idx];
            }
            if(elemCounted == 3){
                return nums[idx];
            }
        }
        return nums[0];
    }
};