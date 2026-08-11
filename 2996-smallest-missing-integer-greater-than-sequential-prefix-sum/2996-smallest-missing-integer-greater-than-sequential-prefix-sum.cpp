class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seq_sum = nums[0];
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                seq_sum += nums[i];
            }else{
                break;
            }
        }
        std::unordered_set<int> numsSet(nums.begin() , nums.end());
        while(numsSet.count(seq_sum)){
            seq_sum++;
        }
        return seq_sum;
    }
};