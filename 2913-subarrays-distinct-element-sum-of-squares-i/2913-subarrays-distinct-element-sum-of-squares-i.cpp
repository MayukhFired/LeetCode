class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // int n = nums.size();
        // int res = 0;
        // for(int i = 0; i < n; i++){
        //     unordered_set<int> s;
        //     for(int j = i; j < n; j++){
        //         s.insert(nums[j]);
        //         res += s.size() * s.size();
        //     }
        // }
        // return res;
        int n = nums.size();
        int id{};
        int sum{};
        vector<int> fr(101);

        for(int i = 0; i < n; i++){
            int cnt{};
            id++;
            for(int j = i; j < n; j++){
                cnt += (fr[nums[j]] != id);
                fr[nums[j]] = id;
                sum += cnt * cnt;
            }
        }
        return sum;
    }
};