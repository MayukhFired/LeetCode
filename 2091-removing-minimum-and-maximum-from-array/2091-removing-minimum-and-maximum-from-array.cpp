class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = 0;
        int maxidx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < nums[minidx]){
                minidx = i;
            }
            if(nums[i] > nums[maxidx]){
                maxidx = i;
            }
        }
        int l = fmin(maxidx , minidx);
        int r = fmax(maxidx , minidx);
        return fmin(fmin(r + 1 , n - l) , l + 1 + n - r);
    }
};