class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0){
            return res;
        }

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<tuple<int , int , int>>>MinHeap;
        int m = nums1.size();
        for(int i = 0; i < min(m , k); i++){
            MinHeap.push({nums1[i] + nums2[0] , i , 0});
        }

        while(!MinHeap.empty() && res.size() < k){
            auto[current_sum , i , j] = MinHeap.top();
            MinHeap.pop();
            res.push_back({nums1[i] , nums2[j]});

            if(j + 1 < nums2.size()){
                MinHeap.push({nums1[i] + nums2[j + 1] , i , j + 1});
            }
        }
        return res;
    }
};